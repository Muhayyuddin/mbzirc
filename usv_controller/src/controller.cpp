#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

#include "std_msgs/msg/string.hpp"

#include <tf2/utils.h>
#include <tf2_ros/transform_listener.h>
#include "usv_msgs/msg/speed_course.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include <eigen3/Eigen/QR>

#include "../include/constants.h"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class USV_Controller : public rclcpp::Node
{
  public:
    USV_Controller()
    : Node("usv_controller"), count_(0)
    {
      publisher_ = this->create_publisher<usv_msgs::msg::SpeedCourse>("speed_heading", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&USV_Controller::timer_callback, this));

      m_leftPub = this->create_publisher<std_msgs::msg::Float32>("left_thrust_cmd", 10);
      m_rightPub = this->create_publisher<std_msgs::msg::Float32>("right_thrust_cmd", 10);

      sub = this->create_subscription<usv_msgs::msg::SpeedCourse>(
      "speed_heading", 1000, std::bind(&USV_Controller::inputCallback, this, std::placeholders::_1));


      //ros::Subscriber subSpeed = nh.subscribe("gps/vel", 1000, &OtterController::speedCallback, this);
      subImu = this->create_subscription<sensor_msgs::msg::Imu>(
      "imu/data", 1000, std::bind(&USV_Controller::imuCallback, this, std::placeholders::_1));

      // Initialize thruster configuration matrix
      T << 50, 50, 0, 0, -0.39 * 50, 0.39 * 50;

      double frequency = 10.0;
      double deltaTime = 1.0 / frequency;
    }

  private:
    void timer_callback()
    {
      auto message = usv_msgs::msg::SpeedCourse();
      message.speed = 0.5;
      message.course = 0.0;

      RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.speed);
      publisher_->publish(message);
    }

    void inputCallback(const usv_msgs::msg::SpeedCourse::SharedPtr msg) 
    {
      RCLCPP_INFO(this->get_logger(), "Receiving: '%f'", msg->speed);
      this->u_d = msg->speed;
      this->psi_d = msg->course;
    }
    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
      this->psi = tf2::getYaw(msg->orientation);
      this->r = msg->angular_velocity.z;
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<usv_msgs::msg::SpeedCourse>::SharedPtr publisher_;
    
    // Publishers for thruster commands
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr m_leftPub;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr m_rightPub;
    
    rclcpp::Subscription<usv_msgs::msg::SpeedCourse>::SharedPtr sub;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subSpeed;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr subImu;
    // Thruster configuration matrix
    Eigen::MatrixXd T;
    size_t count_;
    
    // Sensor data
    double u { 0.0 };
    double psi { 0.0 };
    double r { 0.0 };

    // Desired values
    double u_d { 0.0 };
    double psi_d { 0.0 };
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<USV_Controller>());
  rclcpp::shutdown();
  return 0;
}
