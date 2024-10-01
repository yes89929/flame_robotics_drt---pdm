// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rbpodo_msgs:msg/Response.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__RESPONSE__TRAITS_HPP_
#define RBPODO_MSGS__MSG__DETAIL__RESPONSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rbpodo_msgs/msg/detail/response__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rbpodo_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: category
  {
    out << "category: ";
    rosidl_generator_traits::value_to_yaml(msg.category, out);
    out << ", ";
  }

  // member: msg
  {
    out << "msg: ";
    rosidl_generator_traits::value_to_yaml(msg.msg, out);
    out << ", ";
  }

  // member: error
  {
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: category
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "category: ";
    rosidl_generator_traits::value_to_yaml(msg.category, out);
    out << "\n";
  }

  // member: msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "msg: ";
    rosidl_generator_traits::value_to_yaml(msg.msg, out);
    out << "\n";
  }

  // member: error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error: ";
    rosidl_generator_traits::value_to_yaml(msg.error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::msg::Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::msg::Response & msg)
{
  return rbpodo_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::msg::Response>()
{
  return "rbpodo_msgs::msg::Response";
}

template<>
inline const char * name<rbpodo_msgs::msg::Response>()
{
  return "rbpodo_msgs/msg/Response";
}

template<>
struct has_fixed_size<rbpodo_msgs::msg::Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rbpodo_msgs::msg::Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rbpodo_msgs::msg::Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RBPODO_MSGS__MSG__DETAIL__RESPONSE__TRAITS_HPP_
