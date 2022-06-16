// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_ign_interfaces:msg/WorldControl.idl
// generated code does not contain a copyright notice

#ifndef ROS_IGN_INTERFACES__MSG__DETAIL__WORLD_CONTROL__TRAITS_HPP_
#define ROS_IGN_INTERFACES__MSG__DETAIL__WORLD_CONTROL__TRAITS_HPP_

#include "ros_ign_interfaces/msg/detail/world_control__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'reset'
#include "ros_ign_interfaces/msg/detail/world_reset__traits.hpp"
// Member 'run_to_sim_time'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::msg::WorldControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pause
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pause: ";
    value_to_yaml(msg.pause, out);
    out << "\n";
  }

  // member: step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step: ";
    value_to_yaml(msg.step, out);
    out << "\n";
  }

  // member: multi_step
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "multi_step: ";
    value_to_yaml(msg.multi_step, out);
    out << "\n";
  }

  // member: reset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "reset:\n";
    to_yaml(msg.reset, out, indentation + 2);
  }

  // member: seed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seed: ";
    value_to_yaml(msg.seed, out);
    out << "\n";
  }

  // member: run_to_sim_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "run_to_sim_time:\n";
    to_yaml(msg.run_to_sim_time, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::msg::WorldControl & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::msg::WorldControl>()
{
  return "ros_ign_interfaces::msg::WorldControl";
}

template<>
inline const char * name<ros_ign_interfaces::msg::WorldControl>()
{
  return "ros_ign_interfaces/msg/WorldControl";
}

template<>
struct has_fixed_size<ros_ign_interfaces::msg::WorldControl>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<ros_ign_interfaces::msg::WorldReset>::value> {};

template<>
struct has_bounded_size<ros_ign_interfaces::msg::WorldControl>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<ros_ign_interfaces::msg::WorldReset>::value> {};

template<>
struct is_message<ros_ign_interfaces::msg::WorldControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS_IGN_INTERFACES__MSG__DETAIL__WORLD_CONTROL__TRAITS_HPP_
