// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_ign_interfaces:msg/VideoRecord.idl
// generated code does not contain a copyright notice

#ifndef ROS_IGN_INTERFACES__MSG__DETAIL__VIDEO_RECORD__TRAITS_HPP_
#define ROS_IGN_INTERFACES__MSG__DETAIL__VIDEO_RECORD__TRAITS_HPP_

#include "ros_ign_interfaces/msg/detail/video_record__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::msg::VideoRecord & msg,
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

  // member: start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "start: ";
    value_to_yaml(msg.start, out);
    out << "\n";
  }

  // member: stop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stop: ";
    value_to_yaml(msg.stop, out);
    out << "\n";
  }

  // member: format
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "format: ";
    value_to_yaml(msg.format, out);
    out << "\n";
  }

  // member: save_filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "save_filename: ";
    value_to_yaml(msg.save_filename, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::msg::VideoRecord & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::msg::VideoRecord>()
{
  return "ros_ign_interfaces::msg::VideoRecord";
}

template<>
inline const char * name<ros_ign_interfaces::msg::VideoRecord>()
{
  return "ros_ign_interfaces/msg/VideoRecord";
}

template<>
struct has_fixed_size<ros_ign_interfaces::msg::VideoRecord>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_ign_interfaces::msg::VideoRecord>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_ign_interfaces::msg::VideoRecord>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS_IGN_INTERFACES__MSG__DETAIL__VIDEO_RECORD__TRAITS_HPP_
