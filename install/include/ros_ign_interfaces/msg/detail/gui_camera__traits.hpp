// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_ign_interfaces:msg/GuiCamera.idl
// generated code does not contain a copyright notice

#ifndef ROS_IGN_INTERFACES__MSG__DETAIL__GUI_CAMERA__TRAITS_HPP_
#define ROS_IGN_INTERFACES__MSG__DETAIL__GUI_CAMERA__TRAITS_HPP_

#include "ros_ign_interfaces/msg/detail/gui_camera__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'track'
#include "ros_ign_interfaces/msg/detail/track_visual__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::msg::GuiCamera & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_yaml(msg.header, out, indentation + 2);
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: view_controller
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "view_controller: ";
    value_to_yaml(msg.view_controller, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_yaml(msg.pose, out, indentation + 2);
  }

  // member: track
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track:\n";
    to_yaml(msg.track, out, indentation + 2);
  }

  // member: projection_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "projection_type: ";
    value_to_yaml(msg.projection_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::msg::GuiCamera & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::msg::GuiCamera>()
{
  return "ros_ign_interfaces::msg::GuiCamera";
}

template<>
inline const char * name<ros_ign_interfaces::msg::GuiCamera>()
{
  return "ros_ign_interfaces/msg/GuiCamera";
}

template<>
struct has_fixed_size<ros_ign_interfaces::msg::GuiCamera>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_ign_interfaces::msg::GuiCamera>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_ign_interfaces::msg::GuiCamera>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS_IGN_INTERFACES__MSG__DETAIL__GUI_CAMERA__TRAITS_HPP_
