// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:msg/MoveJb2Point.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__STRUCT_H_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MoveJb2Point in the package rbpodo_msgs.
/**
  * move_jb2_add(...)
 */
typedef struct rbpodo_msgs__msg__MoveJb2Point
{
  float joint[6];
  float speed;
  float acceleration;
  float blending_value;
} rbpodo_msgs__msg__MoveJb2Point;

// Struct for a sequence of rbpodo_msgs__msg__MoveJb2Point.
typedef struct rbpodo_msgs__msg__MoveJb2Point__Sequence
{
  rbpodo_msgs__msg__MoveJb2Point * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__msg__MoveJb2Point__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__STRUCT_H_
