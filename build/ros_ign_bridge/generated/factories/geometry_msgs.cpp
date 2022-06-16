// generated from ros_ign_bridge/resource/pkg_factories.cpp.em


#include "factories/geometry_msgs.hpp"

#include <memory>
#include <string>

#include "factory.hpp"
#include "ros_ign_bridge/convert/geometry_msgs.hpp"

namespace ros_ign_bridge
{

std::shared_ptr<FactoryInterface>
get_factory__geometry_msgs(
  const std::string & ros_type_name,
  const std::string & ign_type_name)
{
  if ((ros_type_name == "geometry_msgs/msg/Point" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Vector3d")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::Point,
        ignition::msgs::Vector3d
      >
    >("geometry_msgs/msg/Point", "ignition.msgs.Vector3d");
  }
  if ((ros_type_name == "geometry_msgs/msg/Pose" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Pose")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::Pose,
        ignition::msgs::Pose
      >
    >("geometry_msgs/msg/Pose", "ignition.msgs.Pose");
  }
  if ((ros_type_name == "geometry_msgs/msg/PoseStamped" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Pose")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::PoseStamped,
        ignition::msgs::Pose
      >
    >("geometry_msgs/msg/PoseStamped", "ignition.msgs.Pose");
  }
  if ((ros_type_name == "geometry_msgs/msg/Quaternion" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Quaternion")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::Quaternion,
        ignition::msgs::Quaternion
      >
    >("geometry_msgs/msg/Quaternion", "ignition.msgs.Quaternion");
  }
  if ((ros_type_name == "geometry_msgs/msg/Transform" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Pose")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::Transform,
        ignition::msgs::Pose
      >
    >("geometry_msgs/msg/Transform", "ignition.msgs.Pose");
  }
  if ((ros_type_name == "geometry_msgs/msg/TransformStamped" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Pose")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::TransformStamped,
        ignition::msgs::Pose
      >
    >("geometry_msgs/msg/TransformStamped", "ignition.msgs.Pose");
  }
  if ((ros_type_name == "geometry_msgs/msg/Twist" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Twist")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::Twist,
        ignition::msgs::Twist
      >
    >("geometry_msgs/msg/Twist", "ignition.msgs.Twist");
  }
  if ((ros_type_name == "geometry_msgs/msg/Vector3" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Vector3d")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::Vector3,
        ignition::msgs::Vector3d
      >
    >("geometry_msgs/msg/Vector3", "ignition.msgs.Vector3d");
  }
  if ((ros_type_name == "geometry_msgs/msg/Wrench" || ros_type_name.empty()) &&
    ign_type_name == "ignition.msgs.Wrench")
  {
    return std::make_shared<
      Factory<
        geometry_msgs::msg::Wrench,
        ignition::msgs::Wrench
      >
    >("geometry_msgs/msg/Wrench", "ignition.msgs.Wrench");
  }
  return nullptr;
}

template<>
void
Factory<
  geometry_msgs::msg::Point,
  ignition::msgs::Vector3d
>::convert_ros_to_ign(
  const geometry_msgs::msg::Point & ros_msg,
  ignition::msgs::Vector3d & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::Point,
  ignition::msgs::Vector3d
>::convert_ign_to_ros(
  const ignition::msgs::Vector3d & ign_msg,
  geometry_msgs::msg::Point & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}
template<>
void
Factory<
  geometry_msgs::msg::Pose,
  ignition::msgs::Pose
>::convert_ros_to_ign(
  const geometry_msgs::msg::Pose & ros_msg,
  ignition::msgs::Pose & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::Pose,
  ignition::msgs::Pose
>::convert_ign_to_ros(
  const ignition::msgs::Pose & ign_msg,
  geometry_msgs::msg::Pose & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}
template<>
void
Factory<
  geometry_msgs::msg::PoseStamped,
  ignition::msgs::Pose
>::convert_ros_to_ign(
  const geometry_msgs::msg::PoseStamped & ros_msg,
  ignition::msgs::Pose & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::PoseStamped,
  ignition::msgs::Pose
>::convert_ign_to_ros(
  const ignition::msgs::Pose & ign_msg,
  geometry_msgs::msg::PoseStamped & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}
template<>
void
Factory<
  geometry_msgs::msg::Quaternion,
  ignition::msgs::Quaternion
>::convert_ros_to_ign(
  const geometry_msgs::msg::Quaternion & ros_msg,
  ignition::msgs::Quaternion & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::Quaternion,
  ignition::msgs::Quaternion
>::convert_ign_to_ros(
  const ignition::msgs::Quaternion & ign_msg,
  geometry_msgs::msg::Quaternion & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}
template<>
void
Factory<
  geometry_msgs::msg::Transform,
  ignition::msgs::Pose
>::convert_ros_to_ign(
  const geometry_msgs::msg::Transform & ros_msg,
  ignition::msgs::Pose & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::Transform,
  ignition::msgs::Pose
>::convert_ign_to_ros(
  const ignition::msgs::Pose & ign_msg,
  geometry_msgs::msg::Transform & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}
template<>
void
Factory<
  geometry_msgs::msg::TransformStamped,
  ignition::msgs::Pose
>::convert_ros_to_ign(
  const geometry_msgs::msg::TransformStamped & ros_msg,
  ignition::msgs::Pose & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::TransformStamped,
  ignition::msgs::Pose
>::convert_ign_to_ros(
  const ignition::msgs::Pose & ign_msg,
  geometry_msgs::msg::TransformStamped & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}
template<>
void
Factory<
  geometry_msgs::msg::Twist,
  ignition::msgs::Twist
>::convert_ros_to_ign(
  const geometry_msgs::msg::Twist & ros_msg,
  ignition::msgs::Twist & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::Twist,
  ignition::msgs::Twist
>::convert_ign_to_ros(
  const ignition::msgs::Twist & ign_msg,
  geometry_msgs::msg::Twist & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}
template<>
void
Factory<
  geometry_msgs::msg::Vector3,
  ignition::msgs::Vector3d
>::convert_ros_to_ign(
  const geometry_msgs::msg::Vector3 & ros_msg,
  ignition::msgs::Vector3d & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::Vector3,
  ignition::msgs::Vector3d
>::convert_ign_to_ros(
  const ignition::msgs::Vector3d & ign_msg,
  geometry_msgs::msg::Vector3 & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}
template<>
void
Factory<
  geometry_msgs::msg::Wrench,
  ignition::msgs::Wrench
>::convert_ros_to_ign(
  const geometry_msgs::msg::Wrench & ros_msg,
  ignition::msgs::Wrench & ign_msg)
{
  ros_ign_bridge::convert_ros_to_ign(ros_msg, ign_msg);
}

template<>
void
Factory<
  geometry_msgs::msg::Wrench,
  ignition::msgs::Wrench
>::convert_ign_to_ros(
  const ignition::msgs::Wrench & ign_msg,
  geometry_msgs::msg::Wrench & ros_msg)
{
  ros_ign_bridge::convert_ign_to_ros(ign_msg, ros_msg);
}

}  // namespace ros_ign_bridge
