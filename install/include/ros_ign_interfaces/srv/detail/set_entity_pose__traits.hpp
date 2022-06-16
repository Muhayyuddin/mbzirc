// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros_ign_interfaces:srv/SetEntityPose.idl
// generated code does not contain a copyright notice

#ifndef ROS_IGN_INTERFACES__SRV__DETAIL__SET_ENTITY_POSE__TRAITS_HPP_
#define ROS_IGN_INTERFACES__SRV__DETAIL__SET_ENTITY_POSE__TRAITS_HPP_

#include "ros_ign_interfaces/srv/detail/set_entity_pose__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'entity'
#include "ros_ign_interfaces/msg/detail/entity__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::srv::SetEntityPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: entity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "entity:\n";
    to_yaml(msg.entity, out, indentation + 2);
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ros_ign_interfaces::srv::SetEntityPose_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::srv::SetEntityPose_Request>()
{
  return "ros_ign_interfaces::srv::SetEntityPose_Request";
}

template<>
inline const char * name<ros_ign_interfaces::srv::SetEntityPose_Request>()
{
  return "ros_ign_interfaces/srv/SetEntityPose_Request";
}

template<>
struct has_fixed_size<ros_ign_interfaces::srv::SetEntityPose_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<ros_ign_interfaces::msg::Entity>::value> {};

template<>
struct has_bounded_size<ros_ign_interfaces::srv::SetEntityPose_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<ros_ign_interfaces::msg::Entity>::value> {};

template<>
struct is_message<ros_ign_interfaces::srv::SetEntityPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const ros_ign_interfaces::srv::SetEntityPose_Response & msg,
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

inline std::string to_yaml(const ros_ign_interfaces::srv::SetEntityPose_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<ros_ign_interfaces::srv::SetEntityPose_Response>()
{
  return "ros_ign_interfaces::srv::SetEntityPose_Response";
}

template<>
inline const char * name<ros_ign_interfaces::srv::SetEntityPose_Response>()
{
  return "ros_ign_interfaces/srv/SetEntityPose_Response";
}

template<>
struct has_fixed_size<ros_ign_interfaces::srv::SetEntityPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros_ign_interfaces::srv::SetEntityPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros_ign_interfaces::srv::SetEntityPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros_ign_interfaces::srv::SetEntityPose>()
{
  return "ros_ign_interfaces::srv::SetEntityPose";
}

template<>
inline const char * name<ros_ign_interfaces::srv::SetEntityPose>()
{
  return "ros_ign_interfaces/srv/SetEntityPose";
}

template<>
struct has_fixed_size<ros_ign_interfaces::srv::SetEntityPose>
  : std::integral_constant<
    bool,
    has_fixed_size<ros_ign_interfaces::srv::SetEntityPose_Request>::value &&
    has_fixed_size<ros_ign_interfaces::srv::SetEntityPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros_ign_interfaces::srv::SetEntityPose>
  : std::integral_constant<
    bool,
    has_bounded_size<ros_ign_interfaces::srv::SetEntityPose_Request>::value &&
    has_bounded_size<ros_ign_interfaces::srv::SetEntityPose_Response>::value
  >
{
};

template<>
struct is_service<ros_ign_interfaces::srv::SetEntityPose>
  : std::true_type
{
};

template<>
struct is_service_request<ros_ign_interfaces::srv::SetEntityPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros_ign_interfaces::srv::SetEntityPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS_IGN_INTERFACES__SRV__DETAIL__SET_ENTITY_POSE__TRAITS_HPP_
