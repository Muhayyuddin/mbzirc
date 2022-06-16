// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_ign_interfaces:msg/TrackVisual.idl
// generated code does not contain a copyright notice

#ifndef ROS_IGN_INTERFACES__MSG__DETAIL__TRACK_VISUAL__TRAITS_HPP_
#define ROS_IGN_INTERFACES__MSG__DETAIL__TRACK_VISUAL__TRAITS_HPP_

#include "ros_ign_interfaces/msg/detail/track_visual__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'xyz'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::msg::TrackVisual & msg,
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

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: inherit_orientation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inherit_orientation: ";
    value_to_yaml(msg.inherit_orientation, out);
    out << "\n";
  }

  // member: min_dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_dist: ";
    value_to_yaml(msg.min_dist, out);
    out << "\n";
  }

  // member: max_dist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_dist: ";
    value_to_yaml(msg.max_dist, out);
    out << "\n";
  }

  // member: is_static
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_static: ";
    value_to_yaml(msg.is_static, out);
    out << "\n";
  }

  // member: use_model_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "use_model_frame: ";
    value_to_yaml(msg.use_model_frame, out);
    out << "\n";
  }

  // member: xyz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "xyz:\n";
    to_yaml(msg.xyz, out, indentation + 2);
  }

  // member: inherit_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inherit_yaw: ";
    value_to_yaml(msg.inherit_yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::msg::TrackVisual & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::msg::TrackVisual>()
{
  return "ros_ign_interfaces::msg::TrackVisual";
}

template<>
inline const char * name<ros_ign_interfaces::msg::TrackVisual>()
{
  return "ros_ign_interfaces/msg/TrackVisual";
}

template<>
struct has_fixed_size<ros_ign_interfaces::msg::TrackVisual>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_ign_interfaces::msg::TrackVisual>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_ign_interfaces::msg::TrackVisual>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS_IGN_INTERFACES__MSG__DETAIL__TRACK_VISUAL__TRAITS_HPP_
