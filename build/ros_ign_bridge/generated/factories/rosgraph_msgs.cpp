// generated from ros_ign_bridge/resource/pkg_factories.cpp.em


#include "factories/rosgraph_msgs.hpp"

#include <memory>
#include <string>

#include "factory.hpp"
#include "ros_ign_bridge/convert/rosgraph_msgs.hpp"

namespace ros_ign_bridge
{

std::shared_ptr<FactoryInterface>
get_factory__rosgraph_msgs(
  const std::string & ros_type_name,
  const std::string & ign_type_name)
{
  if ((ros_type_name == "rosgraph_msgs/msg/Clock" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Clock")
  {
    return std::make_shared<
      Factory<
        rosgraph_msgs::msg::Clock,
        ignition::msgs::Clock
      >
    >("rosgraph_msgs/msg/Clock", "ignition.msgs.Clock");
  }
  return nullptr;
}

template<>
void
Factory<
  rosgraph_msgs::msg::Clock,
  ignition::msgs::Clock
>::convert_ros_to_ign(
  const rosgraph_msgs::msg::Clock & ros_msg,
  ignition::msgs::Clock & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  rosgraph_msgs::msg::Clock,
  ignition::msgs::Clock
>::convert_ign_to_ros(
  const ignition::msgs::Clock & ign_msg,
  rosgraph_msgs::msg::Clock & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}

}  // namespace ros_ign_bridge
