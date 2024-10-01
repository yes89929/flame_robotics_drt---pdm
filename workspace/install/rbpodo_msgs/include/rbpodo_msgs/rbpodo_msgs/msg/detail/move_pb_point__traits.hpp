// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rbpodo_msgs:msg/MovePbPoint.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__TRAITS_HPP_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rbpodo_msgs/msg/detail/move_pb_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rbpodo_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MovePbPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: point
  {
    if (msg.point.size() == 0) {
      out << "point: []";
    } else {
      out << "point: [";
      size_t pending_items = msg.point.size();
      for (auto item : msg.point) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: blending_option
  {
    out << "blending_option: ";
    rosidl_generator_traits::value_to_yaml(msg.blending_option, out);
    out << ", ";
  }

  // member: blending_value
  {
    out << "blending_value: ";
    rosidl_generator_traits::value_to_yaml(msg.blending_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MovePbPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.point.size() == 0) {
      out << "point: []\n";
    } else {
      out << "point:\n";
      for (auto item : msg.point) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: blending_option
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blending_option: ";
    rosidl_generator_traits::value_to_yaml(msg.blending_option, out);
    out << "\n";
  }

  // member: blending_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blending_value: ";
    rosidl_generator_traits::value_to_yaml(msg.blending_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MovePbPoint & msg, bool use_flow_style = false)
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
  const rbpodo_msgs::msg::MovePbPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::msg::MovePbPoint & msg)
{
  return rbpodo_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::msg::MovePbPoint>()
{
  return "rbpodo_msgs::msg::MovePbPoint";
}

template<>
inline const char * name<rbpodo_msgs::msg::MovePbPoint>()
{
  return "rbpodo_msgs/msg/MovePbPoint";
}

template<>
struct has_fixed_size<rbpodo_msgs::msg::MovePbPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::msg::MovePbPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::msg::MovePbPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__TRAITS_HPP_
