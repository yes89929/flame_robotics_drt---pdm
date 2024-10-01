// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rbpodo_msgs:msg/MovePbPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rbpodo_msgs/msg/detail/move_pb_point__rosidl_typesupport_introspection_c.h"
#include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rbpodo_msgs/msg/detail/move_pb_point__functions.h"
#include "rbpodo_msgs/msg/detail/move_pb_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__msg__MovePbPoint__init(message_memory);
}

void rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_fini_function(void * message_memory)
{
  rbpodo_msgs__msg__MovePbPoint__fini(message_memory);
}

size_t rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__size_function__MovePbPoint__point(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__get_const_function__MovePbPoint__point(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__get_function__MovePbPoint__point(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__fetch_function__MovePbPoint__point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__get_const_function__MovePbPoint__point(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__assign_function__MovePbPoint__point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__get_function__MovePbPoint__point(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_message_member_array[4] = {
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__msg__MovePbPoint, point),  // bytes offset in struct
    NULL,  // default value
    rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__size_function__MovePbPoint__point,  // size() function pointer
    rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__get_const_function__MovePbPoint__point,  // get_const(index) function pointer
    rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__get_function__MovePbPoint__point,  // get(index) function pointer
    rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__fetch_function__MovePbPoint__point,  // fetch(index, &value) function pointer
    rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__assign_function__MovePbPoint__point,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__msg__MovePbPoint, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "blending_option",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__msg__MovePbPoint, blending_option),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "blending_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__msg__MovePbPoint, blending_value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_message_members = {
  "rbpodo_msgs__msg",  // message namespace
  "MovePbPoint",  // message name
  4,  // number of fields
  sizeof(rbpodo_msgs__msg__MovePbPoint),
  rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_message_member_array,  // message members
  rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_message_type_support_handle = {
  0,
  &rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, msg, MovePbPoint)() {
  if (!rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__msg__MovePbPoint__rosidl_typesupport_introspection_c__MovePbPoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
