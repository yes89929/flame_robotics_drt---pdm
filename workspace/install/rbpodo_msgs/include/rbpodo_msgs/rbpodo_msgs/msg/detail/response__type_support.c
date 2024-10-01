// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rbpodo_msgs:msg/Response.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rbpodo_msgs/msg/detail/response__rosidl_typesupport_introspection_c.h"
#include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rbpodo_msgs/msg/detail/response__functions.h"
#include "rbpodo_msgs/msg/detail/response__struct.h"


// Include directives for member types
// Member `category`
// Member `msg`
// Member `error`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__msg__Response__init(message_memory);
}

void rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_fini_function(void * message_memory)
{
  rbpodo_msgs__msg__Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_message_member_array[4] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__msg__Response, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "category",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__msg__Response, category),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "msg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__msg__Response, msg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__msg__Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_message_members = {
  "rbpodo_msgs__msg",  // message namespace
  "Response",  // message name
  4,  // number of fields
  sizeof(rbpodo_msgs__msg__Response),
  rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_message_member_array,  // message members
  rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_message_type_support_handle = {
  0,
  &rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, msg, Response)() {
  if (!rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__msg__Response__rosidl_typesupport_introspection_c__Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
