// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rbpodo_msgs:srv/Eval.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__EVAL__TRAITS_HPP_
#define RBPODO_MSGS__SRV__DETAIL__EVAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rbpodo_msgs/srv/detail/eval__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rbpodo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Eval_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: script
  {
    out << "script: ";
    rosidl_generator_traits::value_to_yaml(msg.script, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Eval_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: script
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "script: ";
    rosidl_generator_traits::value_to_yaml(msg.script, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Eval_Request & msg, bool use_flow_style = false)
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
  const rbpodo_msgs::srv::Eval_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::srv::Eval_Request & msg)
{
  return rbpodo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::srv::Eval_Request>()
{
  return "rbpodo_msgs::srv::Eval_Request";
}

template<>
inline const char * name<rbpodo_msgs::srv::Eval_Request>()
{
  return "rbpodo_msgs/srv/Eval_Request";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::Eval_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rbpodo_msgs::srv::Eval_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rbpodo_msgs::srv::Eval_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rbpodo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Eval_Response & msg,
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
  const Eval_Response & msg,
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

inline std::string to_yaml(const Eval_Response & msg, bool use_flow_style = false)
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
  const rbpodo_msgs::srv::Eval_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::srv::Eval_Response & msg)
{
  return rbpodo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::srv::Eval_Response>()
{
  return "rbpodo_msgs::srv::Eval_Response";
}

template<>
inline const char * name<rbpodo_msgs::srv::Eval_Response>()
{
  return "rbpodo_msgs/srv/Eval_Response";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::Eval_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::srv::Eval_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::srv::Eval_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rbpodo_msgs::srv::Eval>()
{
  return "rbpodo_msgs::srv::Eval";
}

template<>
inline const char * name<rbpodo_msgs::srv::Eval>()
{
  return "rbpodo_msgs/srv/Eval";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::Eval>
  : std::integral_constant<
    bool,
    has_fixed_size<rbpodo_msgs::srv::Eval_Request>::value &&
    has_fixed_size<rbpodo_msgs::srv::Eval_Response>::value
  >
{
};

template<>
struct has_bounded_size<rbpodo_msgs::srv::Eval>
  : std::integral_constant<
    bool,
    has_bounded_size<rbpodo_msgs::srv::Eval_Request>::value &&
    has_bounded_size<rbpodo_msgs::srv::Eval_Response>::value
  >
{
};

template<>
struct is_service<rbpodo_msgs::srv::Eval>
  : std::true_type
{
};

template<>
struct is_service_request<rbpodo_msgs::srv::Eval_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rbpodo_msgs::srv::Eval_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RBPODO_MSGS__SRV__DETAIL__EVAL__TRAITS_HPP_
