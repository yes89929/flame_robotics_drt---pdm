// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:msg/Response.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__RESPONSE__STRUCT_H_
#define RBPODO_MSGS__MSG__DETAIL__RESPONSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ACK'.
enum
{
  rbpodo_msgs__msg__Response__ACK = 0
};

/// Constant 'INFO'.
enum
{
  rbpodo_msgs__msg__Response__INFO = 1
};

/// Constant 'WARN'.
enum
{
  rbpodo_msgs__msg__Response__WARN = 2
};

/// Constant 'ERROR'.
enum
{
  rbpodo_msgs__msg__Response__ERROR = 3
};

/// Constant 'UNKNOWN'.
enum
{
  rbpodo_msgs__msg__Response__UNKNOWN = 4
};

// Include directives for member types
// Member 'category'
// Member 'msg'
// Member 'error'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Response in the package rbpodo_msgs.
typedef struct rbpodo_msgs__msg__Response
{
  uint8_t type;
  rosidl_runtime_c__String category;
  rosidl_runtime_c__String msg;
  /// If type is error, retrieve error message from error code
  rosidl_runtime_c__String error;
} rbpodo_msgs__msg__Response;

// Struct for a sequence of rbpodo_msgs__msg__Response.
typedef struct rbpodo_msgs__msg__Response__Sequence
{
  rbpodo_msgs__msg__Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__msg__Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__MSG__DETAIL__RESPONSE__STRUCT_H_
