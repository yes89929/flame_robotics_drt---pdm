// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:srv/TaskStop.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__TASK_STOP__STRUCT_H_
#define RBPODO_MSGS__SRV__DETAIL__TASK_STOP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TaskStop in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__TaskStop_Request
{
  /// Request
  /// timeout (unit: sec)
  float timeout;
} rbpodo_msgs__srv__TaskStop_Request;

// Struct for a sequence of rbpodo_msgs__srv__TaskStop_Request.
typedef struct rbpodo_msgs__srv__TaskStop_Request__Sequence
{
  rbpodo_msgs__srv__TaskStop_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__TaskStop_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TaskStop in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__TaskStop_Response
{
  bool success;
} rbpodo_msgs__srv__TaskStop_Response;

// Struct for a sequence of rbpodo_msgs__srv__TaskStop_Response.
typedef struct rbpodo_msgs__srv__TaskStop_Response__Sequence
{
  rbpodo_msgs__srv__TaskStop_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__TaskStop_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__SRV__DETAIL__TASK_STOP__STRUCT_H_
