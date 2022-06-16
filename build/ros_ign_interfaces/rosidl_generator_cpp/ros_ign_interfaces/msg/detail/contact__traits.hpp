// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_ign_interfaces:msg/Contact.idl
// generated code does not contain a copyright notice

#ifndef ROS_IGN_INTERFACES__MSG__DETAIL__CONTACT__TRAITS_HPP_
#define ROS_IGN_INTERFACES__MSG__DETAIL__CONTACT__TRAITS_HPP_

#include "ros_ign_interfaces/msg/detail/contact__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'collision1'
// Member 'collision2'
#include "ros_ign_interfaces/msg/detail/entity__traits.hpp"
// Member 'positions'
// Member 'normals'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'wrenches'
#include "ros_ign_interfaces/msg/detail/joint_wrench__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::msg::Contact & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: collision1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "collision1:\n";
    to_yaml(msg.collision1, out, indentation + 2);
  }

  // member: collision2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "collision2:\n";
    to_yaml(msg.collision2, out, indentation + 2);
  }

  // member: positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions.size() == 0) {
      out << "positions: []\n";
    } else {
      out << "positions:\n";
      for (auto item : msg.positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: normals
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.normals.size() == 0) {
      out << "normals: []\n";
    } else {
      out << "normals:\n";
      for (auto item : msg.normals) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: depths
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.depths.size() == 0) {
      out << "depths: []\n";
    } else {
      out << "depths:\n";
      for (auto item : msg.depths) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: wrenches
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.wrenches.size() == 0) {
      out << "wrenches: []\n";
    } else {
      out << "wrenches:\n";
      for (auto item : msg.wrenches) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::msg::Contact & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::msg::Contact>()
{
  return "ros_ign_interfaces::msg::Contact";
}

template<>
inline const char * name<ros_ign_interfaces::msg::Contact>()
{
  return "ros_ign_interfaces/msg/Contact";
}

template<>
struct has_fixed_size<ros_ign_interfaces::msg::Contact>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros_ign_interfaces::msg::Contact>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros_ign_interfaces::msg::Contact>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS_IGN_INTERFACES__MSG__DETAIL__CONTACT__TRAITS_HPP_
