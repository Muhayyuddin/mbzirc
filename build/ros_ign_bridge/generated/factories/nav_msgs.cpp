// generated from ros_ign_bridge/resource/pkg_factories.cpp.em


#include "factories/nav_msgs.hpp"

#include <memory>
#include <string>

#include "factory.hpp"
#include "ros_ign_bridge/convert/nav_msgs.hpp"

namespace ros_ign_bridge
{

std::shared_ptr<FactoryInterface>
get_factory__nav_msgs(
  const std::string & ros_type_name,
  const std::string & ign_type_name)
{
  if ((ros_type_name == "nav_msgs/msg/Odometry" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Odometry")
  {
    return std::make_shared<
      Factory<
        nav_msgs::msg::Odometry,
        ignition::msgs::Odometry
      >
    >("nav_msgs/msg/Odometry", "ignition.msgs.Odometry");
  }
  return nullptr;
}

template<>
void
Factory<
  nav_msgs::msg::Odometry,
  ignition::msgs::Odometry
>::convert_ros_to_ign(
  const nav_msgs::msg::Odometry & ros_msg,
  ignition::msgs::Odometry & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  nav_msgs::msg::Odometry,
  ignition::msgs::Odometry
>::convert_ign_to_ros(
  const ignition::msgs::Odometry & ign_msg,
  nav_msgs::msg::Odometry & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}

}  // namespace ros_ign_bridge
