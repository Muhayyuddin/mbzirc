#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

#include "std_msgs/msg/string.hpp"
#include <tf2_ros/buffer.h>

#include <tf2/utils.h>
#include <tf2_ros/transform_listener.h>
#include "geometry_msgs/msg/transform_stamped.hpp"

#include "usv_msgs/msg/speed_course.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include <eigen3/Eigen/QR>
#include "geometry_msgs/msg/vector3_stamped.hpp"
#include <iostream>
#include "../include/constants.h"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class USV_Controller : public rclcpp::Node
{
public:
  USV_Controller()
      : Node("usv_controller"), T(3, 2)
  {
    std::cout<<"in constructor 1"<<std::endl;
    // callback_flags = {false, false, false};
    timer_ = this->create_wall_timer(500ms, std::bind(&USV_Controller::timer_callback, this));
    std::cout<<"in constructor 2"<<std::endl;

    m_leftPub = this->create_publisher<std_msgs::msg::Float64>("/usv/left/thrust/cmd_thrust", 10);
    m_rightPub = this->create_publisher<std_msgs::msg::Float64>("/usv/right/thrust/cmd_thrust", 10);

    sub = this->create_subscription<usv_msgs::msg::SpeedCourse>(
        "speed_heading", 1000, std::bind(&USV_Controller::inputCallback, this, std::placeholders::_1));

    subSpeed = this->create_subscription<geometry_msgs::msg::Vector3Stamped>(
        "usv/velocity", 1000, std::bind(&USV_Controller::speedCallback, this, std::placeholders::_1));

    subImu = this->create_subscription<sensor_msgs::msg::Imu>(
        "/usv/imu/data", 1000, std::bind(&USV_Controller::imuCallback, this, std::placeholders::_1));

    // Initialize thruster configuration matrix
    T << 50, 50, 0, 0, -0.39 * 50, 0.39 * 50;
    std::cout<<T<<std::endl;

  }

  /////////////////////////////Callback methods//////////////////////////////////
  void timer_callback()
  {
    // if (!(callback_flags[0] && callback_flags[1] && !callback_flags[2]))
    // {
    //   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "waiting for sensory data to publish");
    // }
    // else
    {

      // Get SLAM heading
      double psi_slam = getYaw();

      // Speed controller
      auto tauSurge = calculateSurgeForce(deltaTime, u);

      // Heading controller
      auto tauYaw = calculateYawMoment(deltaTime, psi_slam, r);

      // Thrust allocation
      auto cmdThrust = thrustAllocation({tauSurge, 0.0, tauYaw});

      // Publish thruster commands
      std_msgs::msg::Float64 left;
      left.data = static_cast<float>(cmdThrust[0]);
      std_msgs::msg::Float64 right;
      right.data = static_cast<float>(cmdThrust[1]);
      std::cout<<"Publishing Thrust value [ "<<left.data<<", "<<right.data<<" ]"<<std::endl;
      m_leftPub->publish(left);
      m_rightPub->publish(right);
    }
  }

  void inputCallback(const usv_msgs::msg::SpeedCourse::SharedPtr msg)
  {
    callback_flags[0] = true;
    RCLCPP_INFO(this->get_logger(), "Receiving: '%f'", msg->speed);
    this->u_d = msg->speed;
    this->psi_d = msg->course;
  }

  void speedCallback(const geometry_msgs::msg::Vector3Stamped::SharedPtr msg)
  {
    callback_flags[1] = true;

    double dir = std::atan2(msg->vector.y, msg->vector.x) + M_PI_2;
    if (std::abs(dir - psi) > M_PI_2 && std::abs(dir - psi) < 3 * M_PI_2)
    {
     u = -std::sqrt(std::pow(msg->vector.x, 2) + std::pow(msg->vector.y, 2));
    }
    else
    {
      u = std::sqrt(std::pow(msg->vector.x, 2) + std::pow(msg->vector.y, 2));
    }
  }

  void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
  {
    callback_flags[2] = true;

    this->psi = tf2::getYaw(msg->orientation);
    this->r = msg->angular_velocity.z;
   // RCLCPP_INFO(this->get_logger(), "Receiving IMU vel: '%f'", msg->angular_velocity.z);

  }

  ///////////////////////////Controller methods///////////////////////////////

  double getYaw()
  {

    geometry_msgs::msg::TransformStamped tfStamped;
    try
    {
        tfStamped = tfBuffer->lookupTransform("odom", "usv", tf2::TimePointZero);
    }
    catch (tf2::TransformException &ex)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "%s", ex.what());
    }



    return tf2::getYaw(tfStamped.transform.rotation);
  }

  double calculateSurgeForce(double deltaTime, double u)
  {
    static double integralTerm{0.0};

    double u_d_dot{0.0};
    double u_tilde{u - u_d};

    integralTerm += u_tilde * deltaTime;

    return USV_CONST_PRAM::mass_u * (u_d_dot - USV_CONST_PRAM::Kp_u * u_tilde - USV_CONST_PRAM::Ki_u * integralTerm) + USV_CONST_PRAM::damp_u * u;
  }

  double calculateYawMoment(double deltaTime, double psi_slam, double r)
  {
    // TODO: reference model

    static double integralTerm = 0.0;

    double r_d_dot{0.0};
    double r_tilde{0.0}; // r - r_d;
    double psi_tilde{psi_slam - psi_d};
    if (psi_tilde > M_PI)
    {
      psi_tilde -= 2 * M_PI;
    }
    else if (psi_tilde < -M_PI)
    {
      psi_tilde += 2 * M_PI;
    }

    // TODO: anti windup
    // integralTerm += psi_tilde * deltaTime;

    return USV_CONST_PRAM::mass_psi * (r_d_dot - USV_CONST_PRAM::Kd_psi * r_tilde - USV_CONST_PRAM::Kp_psi * psi_tilde - USV_CONST_PRAM::Ki_psi * integralTerm) - USV_CONST_PRAM::damp_psi * r;
  }

  Eigen::Vector2d thrustAllocation(Eigen::Vector3d tau_d)
  {
    // Initialize thruster configuration matrix pseudoinverse
    static bool initialized = false;
    static Eigen::MatrixXd pinv(3, 2);
    if (!initialized)
    {
      initialized = true;
      pinv = T.completeOrthogonalDecomposition().pseudoInverse();
    }

    std::cout<<"Taud is "<< tau_d[0]<<", "<<tau_d[2]<<std::endl;
    // Calculate thruster output
    Eigen::Vector2d u = pinv * tau_d;

    // Ensure in interval [-1, 1]
    u[0] = u[0];//std::min(std::max(u[0], -1.0), 1.0);
    u[1] = u[1];//std::min(std::max(u[1], -1.0), 1.0);

    return u;
  }

  ///////////////////////////////Variables Declerations/////////////////////////
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<usv_msgs::msg::SpeedCourse>::SharedPtr publisher_;

  // Publishers for thruster commands
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr m_leftPub;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr m_rightPub;

  rclcpp::Subscription<usv_msgs::msg::SpeedCourse>::SharedPtr sub;
  rclcpp::Subscription<geometry_msgs::msg::Vector3Stamped>::SharedPtr subSpeed;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subImu;
  // Thruster configuration matrix
  Eigen::MatrixXd T;
  size_t count_{0};

  // Sensor data
  double u{0.0};
  double psi{0.0};
  double r{0.0};

  // Desired values
  double u_d{0.0};
  double psi_d{0.0};
  double frequency = 10.0;
  double deltaTime = 1.0 / frequency;
  bool callback_flags[3] = {false, false, false};
  std::unique_ptr<tf2_ros::Buffer> tfBuffer = std::make_unique<tf2_ros::Buffer>(this->get_clock());

// static tf2_ros::TransformListener tfListener(tfBuffer);
std::shared_ptr<tf2_ros::TransformListener> tfListener = std::make_shared<tf2_ros::TransformListener>(*tfBuffer);

};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);

  rclcpp::spin(std::make_shared<USV_Controller>());
  std::cout << "i am in main" << std::endl;

  rclcpp::shutdown();
  return 0;
}
