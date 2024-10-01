// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rbpodo_msgs:msg/MovePbPoint.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__FUNCTIONS_H_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rbpodo_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rbpodo_msgs/msg/detail/move_pb_point__struct.h"

/// Initialize msg/MovePbPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__msg__MovePbPoint
 * )) before or use
 * rbpodo_msgs__msg__MovePbPoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__msg__MovePbPoint__init(rbpodo_msgs__msg__MovePbPoint * msg);

/// Finalize msg/MovePbPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__msg__MovePbPoint__fini(rbpodo_msgs__msg__MovePbPoint * msg);

/// Create msg/MovePbPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__msg__MovePbPoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__msg__MovePbPoint *
rbpodo_msgs__msg__MovePbPoint__create();

/// Destroy msg/MovePbPoint message.
/**
 * It calls
 * rbpodo_msgs__msg__MovePbPoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__msg__MovePbPoint__destroy(rbpodo_msgs__msg__MovePbPoint * msg);

/// Check for msg/MovePbPoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__msg__MovePbPoint__are_equal(const rbpodo_msgs__msg__MovePbPoint * lhs, const rbpodo_msgs__msg__MovePbPoint * rhs);

/// Copy a msg/MovePbPoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__msg__MovePbPoint__copy(
  const rbpodo_msgs__msg__MovePbPoint * input,
  rbpodo_msgs__msg__MovePbPoint * output);

/// Initialize array of msg/MovePbPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__msg__MovePbPoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__msg__MovePbPoint__Sequence__init(rbpodo_msgs__msg__MovePbPoint__Sequence * array, size_t size);

/// Finalize array of msg/MovePbPoint messages.
/**
 * It calls
 * rbpodo_msgs__msg__MovePbPoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__msg__MovePbPoint__Sequence__fini(rbpodo_msgs__msg__MovePbPoint__Sequence * array);

/// Create array of msg/MovePbPoint messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__msg__MovePbPoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__msg__MovePbPoint__Sequence *
rbpodo_msgs__msg__MovePbPoint__Sequence__create(size_t size);

/// Destroy array of msg/MovePbPoint messages.
/**
 * It calls
 * rbpodo_msgs__msg__MovePbPoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__msg__MovePbPoint__Sequence__destroy(rbpodo_msgs__msg__MovePbPoint__Sequence * array);

/// Check for msg/MovePbPoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__msg__MovePbPoint__Sequence__are_equal(const rbpodo_msgs__msg__MovePbPoint__Sequence * lhs, const rbpodo_msgs__msg__MovePbPoint__Sequence * rhs);

/// Copy an array of msg/MovePbPoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__msg__MovePbPoint__Sequence__copy(
  const rbpodo_msgs__msg__MovePbPoint__Sequence * input,
  rbpodo_msgs__msg__MovePbPoint__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__FUNCTIONS_H_
