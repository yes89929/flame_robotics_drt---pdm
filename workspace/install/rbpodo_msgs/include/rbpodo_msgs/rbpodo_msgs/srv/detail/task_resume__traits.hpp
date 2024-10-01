// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rbpodo_msgs:srv/TaskResume.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__TASK_RESUME__TRAITS_HPP_
#define RBPODO_MSGS__SRV__DETAIL__TASK_RESUME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rbpodo_msgs/srv/detail/task_resume__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rbpodo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TaskResume_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: collision
  {
    out << "collision: ";
    rosidl_generator_traits::value_to_yaml(msg.collision, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskResume_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: collision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "collision: ";
    rosidl_generator_traits::value_to_yaml(msg.collision, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskResume_Request & msg, bool use_flow_style = false)
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
  const rbpodo_msgs::srv::TaskResume_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::srv::TaskResume_Request & msg)
{
  return rbpodo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::srv::TaskResume_Request>()
{
  return "rbpodo_msgs::srv::TaskResume_Request";
}

template<>
inline const char * name<rbpodo_msgs::srv::TaskResume_Request>()
{
  return "rbpodo_msgs/srv/TaskResume_Request";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::TaskResume_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::srv::TaskResume_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::srv::TaskResume_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rbpodo_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const TaskResume_Response & msg,
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
  const TaskResume_Response & msg,
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

inline std::string to_yaml(const TaskResume_Response & msg, bool use_flow_style = false)
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
  const rbpodo_msgs::srv::TaskResume_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::srv::TaskResume_Response & msg)
{
  return rbpodo_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::srv::TaskResume_Response>()
{
  return "rbpodo_msgs::srv::TaskResume_Response";
}

template<>
inline const char * name<rbpodo_msgs::srv::TaskResume_Response>()
{
  return "rbpodo_msgs/srv/TaskResume_Response";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::TaskResume_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::srv::TaskResume_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::srv::TaskResume_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rbpodo_msgs::srv::TaskResume>()
{
  return "rbpodo_msgs::srv::TaskResume";
}

template<>
inline const char * name<rbpodo_msgs::srv::TaskResume>()
{
  return "rbpodo_msgs/srv/TaskResume";
}

template<>
struct has_fixed_size<rbpodo_msgs::srv::TaskResume>
  : std::integral_constant<
    bool,
    has_fixed_size<rbpodo_msgs::srv::TaskResume_Request>::value &&
    has_fixed_size<rbpodo_msgs::srv::TaskResume_Response>::value
  >
{
};

template<>
struct has_bounded_size<rbpodo_msgs::srv::TaskResume>
  : std::integral_constant<
    bool,
    has_bounded_size<rbpodo_msgs::srv::TaskResume_Request>::value &&
    has_bounded_size<rbpodo_msgs::srv::TaskResume_Response>::value
  >
{
};

template<>
struct is_service<rbpodo_msgs::srv::TaskResume>
  : std::true_type
{
};

template<>
struct is_service_request<rbpodo_msgs::srv::TaskResume_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rbpodo_msgs::srv::TaskResume_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RBPODO_MSGS__SRV__DETAIL__TASK_RESUME__TRAITS_HPP_
