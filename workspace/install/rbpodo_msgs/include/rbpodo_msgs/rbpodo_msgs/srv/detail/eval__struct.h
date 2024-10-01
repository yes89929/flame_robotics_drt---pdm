// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:srv/Eval.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__EVAL__STRUCT_H_
#define RBPODO_MSGS__SRV__DETAIL__EVAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'script'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Eval in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__Eval_Request
{
  rosidl_runtime_c__String script;
} rbpodo_msgs__srv__Eval_Request;

// Struct for a sequence of rbpodo_msgs__srv__Eval_Request.
typedef struct rbpodo_msgs__srv__Eval_Request__Sequence
{
  rbpodo_msgs__srv__Eval_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__Eval_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Eval in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__Eval_Response
{
  bool success;
} rbpodo_msgs__srv__Eval_Response;

// Struct for a sequence of rbpodo_msgs__srv__Eval_Response.
typedef struct rbpodo_msgs__srv__Eval_Response__Sequence
{
  rbpodo_msgs__srv__Eval_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__Eval_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__SRV__DETAIL__EVAL__STRUCT_H_
