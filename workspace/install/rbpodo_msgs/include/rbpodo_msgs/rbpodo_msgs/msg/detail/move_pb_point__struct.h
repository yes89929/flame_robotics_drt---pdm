// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:msg/MovePbPoint.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__STRUCT_H_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'BLENDING_OPTION_RATIO'.
enum
{
  rbpodo_msgs__msg__MovePbPoint__BLENDING_OPTION_RATIO = 0
};

/// Constant 'BLENDING_OPTION_DISTANCE'.
enum
{
  rbpodo_msgs__msg__MovePbPoint__BLENDING_OPTION_DISTANCE = 1
};

/// Struct defined in msg/MovePbPoint in the package rbpodo_msgs.
typedef struct rbpodo_msgs__msg__MovePbPoint
{
  float point[6];
  float speed;
  uint8_t blending_option;
  float blending_value;
} rbpodo_msgs__msg__MovePbPoint;

// Struct for a sequence of rbpodo_msgs__msg__MovePbPoint.
typedef struct rbpodo_msgs__msg__MovePbPoint__Sequence
{
  rbpodo_msgs__msg__MovePbPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__msg__MovePbPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__STRUCT_H_
