// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_ign_interfaces:srv/ControlWorld.idl
// generated code does not contain a copyright notice

#ifndef ROS_IGN_INTERFACES__SRV__DETAIL__CONTROL_WORLD__TRAITS_HPP_
#define ROS_IGN_INTERFACES__SRV__DETAIL__CONTROL_WORLD__TRAITS_HPP_

#include "ros_ign_interfaces/srv/detail/control_world__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'world_control'
#include "ros_ign_interfaces/msg/detail/world_control__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::srv::ControlWorld_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: world_control
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "world_control:\n";
    to_yaml(msg.world_control, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::srv::ControlWorld_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::srv::ControlWorld_Request>()
{
  return "ros_ign_interfaces::srv::ControlWorld_Request";
}

template<>
inline const char * name<ros_ign_interfaces::srv::ControlWorld_Request>()
{
  return "ros_ign_interfaces/srv/ControlWorld_Request";
}

template<>
struct has_fixed_size<ros_ign_interfaces::srv::ControlWorld_Request>
  : std::integral_constant<bool, has_fixed_size<ros_ign_interfaces::msg::WorldControl>::value> {};

template<>
struct has_bounded_size<ros_ign_interfaces::srv::ControlWorld_Request>
  : std::integral_constant<bool, has_bounded_size<ros_ign_interfaces::msg::WorldControl>::value> {};

template<>
struct is_message<ros_ign_interfaces::srv::ControlWorld_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::srv::ControlWorld_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::srv::ControlWorld_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::srv::ControlWorld_Response>()
{
  return "ros_ign_interfaces::srv::ControlWorld_Response";
}

template<>
inline const char * name<ros_ign_interfaces::srv::ControlWorld_Response>()
{
  return "ros_ign_interfaces/srv/ControlWorld_Response";
}

template<>
struct has_fixed_size<ros_ign_interfaces::srv::ControlWorld_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_ign_interfaces::srv::ControlWorld_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_ign_interfaces::srv::ControlWorld_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros_ign_interfaces::srv::ControlWorld>()
{
  return "ros_ign_interfaces::srv::ControlWorld";
}

template<>
inline const char * name<ros_ign_interfaces::srv::ControlWorld>()
{
  return "ros_ign_interfaces/srv/ControlWorld";
}

template<>
struct has_fixed_size<ros_ign_interfaces::srv::ControlWorld>
  : std::integral_constant<
    bool,
    has_fixed_size<ros_ign_interfaces::srv::ControlWorld_Request>::value &&
    has_fixed_size<ros_ign_interfaces::srv::ControlWorld_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros_ign_interfaces::srv::ControlWorld>
  : std::integral_constant<
    bool,
    has_bounded_size<ros_ign_interfaces::srv::ControlWorld_Request>::value &&
    has_bounded_size<ros_ign_interfaces::srv::ControlWorld_Response>::value
  >
{
};

template<>
struct is_service<ros_ign_interfaces::srv::ControlWorld>
  : std::true_type
{
};

template<>
struct is_service_request<ros_ign_interfaces::srv::ControlWorld_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros_ign_interfaces::srv::ControlWorld_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS_IGN_INTERFACES__SRV__DETAIL__CONTROL_WORLD__TRAITS_HPP_
