#include <chrono>

#include "rclcpp/rclcpp.hpp"

#include <tf2/utils.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>

#include <cmath>

#include "usv_msgs/msg/speed_course.hpp"

#include "geometry_msgs/msg/pose_stamped.hpp"

#include "nav_msgs/msg/path.hpp"

#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class Guidance : public rclcpp::Node
{
public:
    Guidance() : Node("guidance")
    {
        // todo: debug and take as param
        //  m_maxSpeed = this->declare_parameter("max_speed", 1.5).as_double();
        //  m_maxSpeedTurn = this->declare_parameter("max_speed_turn", 0.6).as_double();
        //  m_minSpeed = this->declare_parameter("min_speed", 0.4).as_double();
        m_maxSpeed = 1.5;
        m_maxSpeedTurn = 0.6;
        m_minSpeed = 0.4;
        subodom=this->create_subscription<nav_msgs::msg::Odometry>(
      "/usv/odom", 10, std::bind(&Guidance::odom_callback, this, std::placeholders::_1));
        //   ros::Subscriber dubinsPathSub =
        //   nh.subscribe("simple_dubins_path", 1000, &Guidance::newPath, this);
        m_controllerPub = this->create_publisher<usv_msgs::msg::SpeedCourse>("speed_heading", 100);
        twistPub = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 100);

        //timer_ = this->create_wall_timer(100ms, std::bind(&Guidance::timer_callback, this));

        m_path.header.stamp = this->get_clock()->now();
        m_path.header.frame_id = "odom";
        m_path.poses.clear();

        // generate straight line segment
        int increment = 0;
        for (int i{0}; i < 5; ++i)
        {
            increment += 10;

            geometry_msgs::msg::PoseStamped point;
            point.header.stamp = this->get_clock()->now();
            point.header.frame_id = "odom";
            point.pose.position.x = -40 ;
            point.pose.position.y =  increment;
            point.pose.orientation.x = 0;
            point.pose.orientation.y = 0;
            point.pose.orientation.z = 0;
            point.pose.orientation.w = 1;
            m_path.poses.push_back(point);
        }
        for (int i{0}; i < m_path.poses.size(); ++i)
        {
            std::cout << "path point "
                      << "[ " << m_path.poses[i].pose.position.x << ", " << m_path.poses[i].pose.position.y << " ]"<<std::endl;
        }
    }
void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    double x = msg->pose.pose.position.x;
    double y = msg->pose.pose.position.y;
    double psi = tf2::getYaw(msg->pose.pose.orientation);
    std::cout << "Received Pose is " << x << " " << y << " " << psi << std::endl;
    followPath(x, y, psi);
}
// // Get the pose of the robot in the map frame
// void timer_callback()
// {
//     geometry_msgs::msg::TransformStamped tfStamped;
//     try
//     {
//         tfStamped = tfBuffer->lookupTransform("odom", "usv", tf2::TimePointZero);
//     }
//     catch (tf2::TransformException &ex)
//     {
//         RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "%s", ex.what());
//     }

//     double x = tfStamped.transform.translation.x;
//     double y = tfStamped.transform.translation.y;
//     double psi = tf2::getYaw(tfStamped.transform.rotation);
//     std::cout << "Received Pose is " << x << " " << y << " " << psi << std::endl;
//     followPath(x, y, psi);
// }
~Guidance() {}

//void newPath(const nav_msgs::msg::Path &path) { m_path = path; }

void followPath(double x, double y, double psi)
// TODO: cuts turns, how to fix?
{
     geometry_msgs::msg::Twist twist_cmd;
    // Finished?
    if (m_path.poses.size() <= 1)
    {
        usv_msgs::msg::SpeedCourse msg;
        msg.speed = 0.0;
        msg.course = psi;
        twist_cmd.angular.z = psi;
        twist_cmd.linear.x = 0.0;
        std::cout<<"Publishing Speed and course value to follow path [ "<< msg.speed<<" , "<<msg.course<<" ]"<<std::endl;

        m_controllerPub->publish(msg);
        twistPub->publish(twist_cmd);
        return;
    }

    // Identify closest point on path
    std::vector<geometry_msgs::msg::PoseStamped>::iterator closest;
    double minDist = std::numeric_limits<double>::max();
    for (auto it = m_path.poses.begin(); it != m_path.poses.end(); it++)
    {
        double dist = std::sqrt(std::pow(x - it->pose.position.x, 2) +
                                std::pow(y - it->pose.position.y, 2));
        if (dist < minDist)
        {
            minDist = dist;
            closest = it;
        }
    }

    // Store closest
    geometry_msgs::msg::PoseStamped pose_d = *closest;
    std::cout<<"Closest point is  [ "<< pose_d.pose.position.x<<" , "<<pose_d.pose.position.y<<" ]"<<std::endl;

    // Erase previous elements
    m_path.poses.erase(m_path.poses.begin(), closest);

    // Path tangential angle
    double gamma_p = tf2::getYaw(pose_d.pose.orientation);

    // Cross-track error
    double y_e = -(x - pose_d.pose.position.x) * std::sin(gamma_p) +
                 (y - pose_d.pose.position.y) * std::cos(gamma_p);
    std::cout<<"Difference is  [ "<<(x - pose_d.pose.position.x)<<" , "<<(y - pose_d.pose.position.y)<<" ]"<<std::endl;

    std::cout<<"Cross track error [ "<< y_e<<" ]"<<std::endl;

    // Time-varying lookahead distance
    double delta_y_e =
        (delta_max - delta_min) * std::exp(-delta_k * std::pow(y_e, 2)) +
        delta_min;
    // if turning => small lookahead distance
    bool isTurning = false;
    if ((closest + 1) != m_path.poses.end())
    {
        double nextAngle = tf2::getYaw((*(closest + 1)).pose.orientation);
        if (std::fabs(gamma_p - nextAngle) > std::numeric_limits<double>::epsilon())
        {
            delta_y_e = delta_min;
            isTurning = true;
        }
    }

    // velocity-path relative angle
    double chi_r = std::atan(-y_e / delta_y_e);

    // desired course angle
    double chi_d = gamma_p + chi_r;

    // calculate error in heading
    double chi_err = chi_d - psi;
    while (chi_err > M_PI)
    {
        chi_err -= 2 * M_PI;
    }
    while (chi_err < -M_PI)
    {
        chi_err += 2 * M_PI;
    }

    // calculate desired speed
    double u = m_maxSpeed * (1 - std::abs(y_e) / 5 - std::abs(chi_err) / M_PI_2);
    u = std::max(u, m_minSpeed);
    if (isTurning)
        u = m_maxSpeedTurn;

    // Publish speed and course to controller
    usv_msgs::msg::SpeedCourse msg;
    msg.speed = u;
    msg.course = chi_d;

    twist_cmd.angular.z = chi_d;
    twist_cmd.linear.x = u;
    std::cout<<"Speed and course value to follow path [ "<< u<<" , "<<chi_d<<" ]"<<std::endl;
    m_controllerPub->publish(msg);
    twistPub->publish(twist_cmd);


    // ROS_INFO_STREAM("psi_d: " << chi_d << " psi: " << psi);
    // ROS_INFO_STREAM("u_d: " << u);
}

nav_msgs::msg::Path m_path;
rclcpp::TimerBase::SharedPtr timer_;
rclcpp::Publisher<usv_msgs::msg::SpeedCourse>::SharedPtr m_controllerPub;
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr twistPub;
std::unique_ptr<tf2_ros::Buffer> tfBuffer = std::make_unique<tf2_ros::Buffer>(this->get_clock());

// static tf2_ros::TransformListener tfListener(tfBuffer);
std::shared_ptr<tf2_ros::TransformListener> tfListener = std::make_shared<tf2_ros::TransformListener>(*tfBuffer);
rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subodom;

// lookahead distance
double DELTA = 0.5;

// time-varying lookahead distance
double delta_max = 4.0;
double delta_min = 1.0;
double delta_k = 1.0;

// circle of acceptance
double R = 2.0;

double m_maxSpeed;
double m_maxSpeedTurn;
double m_minSpeed;
}
;

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Guidance>());
    rclcpp::shutdown();
    return 0;
}