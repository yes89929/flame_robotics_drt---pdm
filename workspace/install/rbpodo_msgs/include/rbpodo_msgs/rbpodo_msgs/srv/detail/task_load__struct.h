// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:srv/TaskLoad.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__STRUCT_H_
#define RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'program_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/TaskLoad in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__TaskLoad_Request
{
  /// Request
  /// name of the program to be loaded
  rosidl_runtime_c__String program_name;
  /// timeout (unit: sec)
  float timeout;
} rbpodo_msgs__srv__TaskLoad_Request;

// Struct for a sequence of rbpodo_msgs__srv__TaskLoad_Request.
typedef struct rbpodo_msgs__srv__TaskLoad_Request__Sequence
{
  rbpodo_msgs__srv__TaskLoad_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__TaskLoad_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TaskLoad in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__TaskLoad_Response
{
  bool success;
} rbpodo_msgs__srv__TaskLoad_Response;

// Struct for a sequence of rbpodo_msgs__srv__TaskLoad_Response.
typedef struct rbpodo_msgs__srv__TaskLoad_Response__Sequence
{
  rbpodo_msgs__srv__TaskLoad_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__TaskLoad_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__STRUCT_H_
