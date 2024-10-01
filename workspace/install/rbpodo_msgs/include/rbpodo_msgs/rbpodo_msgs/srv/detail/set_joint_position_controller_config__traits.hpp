// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rbpodo_msgs:srv/SetJointPositionControllerConfig.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__SET_JOINT_POSITION_CONTROLLER_CONFIG__TRAITS_HPP_
#define RBPODO_MSGS__SRV__DETAIL__SET_JOINT_POSITION_CONTROLLER_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rbpodo_msgs/srv/detail/set_joint_position_controller_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rbpodo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetJointPositionControllerConfig_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: t1
  {
    out << "t1: ";
    rosidl_generator_traits::value_to_yaml(msg.t1, out);
    out << ", ";
  }

  // member: t2
  {
    out << "t2: ";
    rosidl_generator_traits::value_to_yaml(msg.t2, out);
    out << ", ";
  }

  // member: gain
  {
    out << "gain: ";
    rosidl_generator_traits::value_to_yaml(msg.gain, out);
    out << ", ";
  }

  // member: alpha
  {
    out << "alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.alpha, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetJointPositionControllerConfig_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: t1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t1: ";
    rosidl_generator_traits::value_to_yaml(msg.t1, out);
    out << "\n";
  }

  // member: t2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t2: ";
    rosidl_generator_traits::value_to_yaml(msg.t2, out);
    out << "\n";
  }

  // member: gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gain: ";
    rosidl_generator_traits::value_to_yaml(msg.gain, out);
    out << "\n";
  }

  // member: alpha
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "alpha: ";
    rosidl_generator_traits::value_to_yaml(msg.alpha, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetJointPositionControllerConfig_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::srv::SetJointPositionControllerConfig_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::srv::SetJointPositionControllerConfig_Request & msg)
{
  return rbpodo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::srv::SetJointPositionControllerConfig_Request>()
{
  return "rbpodo_msgs::srv::SetJointPositionControllerConfig_Request";
}

template<>
inline const char * name<rbpodo_msgs::srv::SetJointPositionControllerConfig_Request>()
{
  return "rbpodo_msgs/srv/SetJointPositionControllerConfig_Request";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::SetJointPositionControllerConfig_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::srv::SetJointPositionControllerConfig_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::srv::SetJointPositionControllerConfig_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rbpodo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetJointPositionControllerConfig_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetJointPositionControllerConfig_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetJointPositionControllerConfig_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::srv::SetJointPositionControllerConfig_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::srv::SetJointPositionControllerConfig_Response & msg)
{
  return rbpodo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::srv::SetJointPositionControllerConfig_Response>()
{
  return "rbpodo_msgs::srv::SetJointPositionControllerConfig_Response";
}

template<>
inline const char * name<rbpodo_msgs::srv::SetJointPositionControllerConfig_Response>()
{
  return "rbpodo_msgs/srv/SetJointPositionControllerConfig_Response";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::SetJointPositionControllerConfig_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::srv::SetJointPositionControllerConfig_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::srv::SetJointPositionControllerConfig_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rbpodo_msgs::srv::SetJointPositionControllerConfig>()
{
  return "rbpodo_msgs::srv::SetJointPositionControllerConfig";
}

template<>
inline const char * name<rbpodo_msgs::srv::SetJointPositionControllerConfig>()
{
  return "rbpodo_msgs/srv/SetJointPositionControllerConfig";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::SetJointPositionControllerConfig>
  : std::integral_constant<
    bool,
    has_fixed_size<rbpodo_msgs::srv::SetJointPositionControllerConfig_Request>::value &&
    has_fixed_size<rbpodo_msgs::srv::SetJointPositionControllerConfig_Response>::value
  >
{
};

template<>
struct has_bounded_size<rbpodo_msgs::srv::SetJointPositionControllerConfig>
  : std::integral_constant<
    bool,
    has_bounded_size<rbpodo_msgs::srv::SetJointPositionControllerConfig_Request>::value &&
    has_bounded_size<rbpodo_msgs::srv::SetJointPositionControllerConfig_Response>::value
  >
{
};

template<>
struct is_service<rbpodo_msgs::srv::SetJointPositionControllerConfig>
  : std::true_type
{
};

template<>
struct is_service_request<rbpodo_msgs::srv::SetJointPositionControllerConfig_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rbpodo_msgs::srv::SetJointPositionControllerConfig_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RBPODO_MSGS__SRV__DETAIL__SET_JOINT_POSITION_CONTROLLER_CONFIG__TRAITS_HPP_
