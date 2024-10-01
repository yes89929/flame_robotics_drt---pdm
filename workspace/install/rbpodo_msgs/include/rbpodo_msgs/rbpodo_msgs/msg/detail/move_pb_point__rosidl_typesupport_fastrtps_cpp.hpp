// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from rbpodo_msgs:msg/MovePbPoint.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rbpodo_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "rbpodo_msgs/msg/detail/move_pb_point__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace rbpodo_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rbpodo_msgs
cdr_serialize(
  const rbpodo_msgs::msg::MovePbPoint & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rbpodo_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rbpodo_msgs::msg::MovePbPoint & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rbpodo_msgs
get_serialized_size(
  const rbpodo_msgs::msg::MovePbPoint & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rbpodo_msgs
max_serialized_size_MovePbPoint(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rbpodo_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rbpodo_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rbpodo_msgs, msg, MovePbPoint)();

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
