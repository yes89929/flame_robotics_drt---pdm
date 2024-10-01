// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rbpodo_msgs:msg/MoveJb2Point.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rbpodo_msgs/msg/detail/move_jb2_point__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rbpodo_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MoveJb2Point_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rbpodo_msgs::msg::MoveJb2Point(_init);
}

void MoveJb2Point_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rbpodo_msgs::msg::MoveJb2Point *>(message_memory);
  typed_message->~MoveJb2Point();
}

size_t size_function__MoveJb2Point__joint(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__MoveJb2Point__joint(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__MoveJb2Point__joint(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__MoveJb2Point__joint(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__MoveJb2Point__joint(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__MoveJb2Point__joint(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__MoveJb2Point__joint(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MoveJb2Point_message_member_array[4] = {
  {
    "joint",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::MoveJb2Point, joint),  // bytes offset in struct
    nullptr,  // default value
    size_function__MoveJb2Point__joint,  // size() function pointer
    get_const_function__MoveJb2Point__joint,  // get_const(index) function pointer
    get_function__MoveJb2Point__joint,  // get(index) function pointer
    fetch_function__MoveJb2Point__joint,  // fetch(index, &value) function pointer
    assign_function__MoveJb2Point__joint,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::MoveJb2Point, speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "acceleration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::MoveJb2Point, acceleration),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "blending_value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::MoveJb2Point, blending_value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MoveJb2Point_message_members = {
  "rbpodo_msgs::msg",  // message namespace
  "MoveJb2Point",  // message name
  4,  // number of fields
  sizeof(rbpodo_msgs::msg::MoveJb2Point),
  MoveJb2Point_message_member_array,  // message members
  MoveJb2Point_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveJb2Point_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MoveJb2Point_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MoveJb2Point_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rbpodo_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rbpodo_msgs::msg::MoveJb2Point>()
{
  return &::rbpodo_msgs::msg::rosidl_typesupport_introspection_cpp::MoveJb2Point_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rbpodo_msgs, msg, MoveJb2Point)() {
  return &::rbpodo_msgs::msg::rosidl_typesupport_introspection_cpp::MoveJb2Point_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
