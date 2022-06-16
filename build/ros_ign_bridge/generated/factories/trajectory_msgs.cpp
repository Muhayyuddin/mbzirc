// generated from ros_ign_bridge/resource/pkg_factories.cpp.em


#include "factories/trajectory_msgs.hpp"

#include <memory>
#include <string>

#include "factory.hpp"
#include "ros_ign_bridge/convert/trajectory_msgs.hpp"

namespace ros_ign_bridge
{

std::shared_ptr<FactoryInterface>
get_factory__trajectory_msgs(
  const std::string & ros_type_name,
  const std::string & ign_type_name)
{
  if ((ros_type_name == "trajectory_msgs/msg/JointTrajectory" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.JointTrajectory")
  {
    return std::make_shared<
      Factory<
        trajectory_msgs::msg::JointTrajectory,
        ignition::msgs::JointTrajectory
      >
    >("trajectory_msgs/msg/JointTrajectory", "ignition.msgs.JointTrajectory");
  }
  return nullptr;
}

template<>
void
Factory<
  trajectory_msgs::msg::JointTrajectory,
  ignition::msgs::JointTrajectory
>::convert_ros_to_ign(
  const trajectory_msgs::msg::JointTrajectory & ros_msg,
  ignition::msgs::JointTrajectory & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  trajectory_msgs::msg::JointTrajectory,
  ignition::msgs::JointTrajectory
>::convert_ign_to_ros(
  const ignition::msgs::JointTrajectory & ign_msg,
  trajectory_msgs::msg::JointTrajectory & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}

}  // namespace ros_ign_bridge
