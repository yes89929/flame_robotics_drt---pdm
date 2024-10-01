// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:srv/TaskPlay.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__TASK_PLAY__STRUCT_H_
#define RBPODO_MSGS__SRV__DETAIL__TASK_PLAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/TaskPlay in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__TaskPlay_Request
{
  /// Request
  float timeout;
} rbpodo_msgs__srv__TaskPlay_Request;

// Struct for a sequence of rbpodo_msgs__srv__TaskPlay_Request.
typedef struct rbpodo_msgs__srv__TaskPlay_Request__Sequence
{
  rbpodo_msgs__srv__TaskPlay_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__TaskPlay_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/TaskPlay in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__TaskPlay_Response
{
  bool success;
} rbpodo_msgs__srv__TaskPlay_Response;

// Struct for a sequence of rbpodo_msgs__srv__TaskPlay_Response.
typedef struct rbpodo_msgs__srv__TaskPlay_Response__Sequence
{
  rbpodo_msgs__srv__TaskPlay_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__TaskPlay_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__SRV__DETAIL__TASK_PLAY__STRUCT_H_
