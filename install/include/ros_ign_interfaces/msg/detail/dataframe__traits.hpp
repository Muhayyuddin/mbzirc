// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_ign_interfaces:msg/Dataframe.idl
// generated code does not contain a copyright notice

#ifndef ROS_IGN_INTERFACES__MSG__DETAIL__DATAFRAME__TRAITS_HPP_
#define ROS_IGN_INTERFACES__MSG__DETAIL__DATAFRAME__TRAITS_HPP_

#include "ros_ign_interfaces/msg/detail/dataframe__struct.hpp"
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
  const ros_ign_interfaces::msg::Dataframe & msg,
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

  // member: src_address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "src_address: ";
    value_to_yaml(msg.src_address, out);
    out << "\n";
  }

  // member: dst_address
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dst_address: ";
    value_to_yaml(msg.dst_address, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: rssi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rssi: ";
    value_to_yaml(msg.rssi, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::msg::Dataframe & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::msg::Dataframe>()
{
  return "ros_ign_interfaces::msg::Dataframe";
}

template<>
inline const char * name<ros_ign_interfaces::msg::Dataframe>()
{
  return "ros_ign_interfaces/msg/Dataframe";
}

template<>
struct has_fixed_size<ros_ign_interfaces::msg::Dataframe>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_ign_interfaces::msg::Dataframe>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_ign_interfaces::msg::Dataframe>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS_IGN_INTERFACES__MSG__DETAIL__DATAFRAME__TRAITS_HPP_
