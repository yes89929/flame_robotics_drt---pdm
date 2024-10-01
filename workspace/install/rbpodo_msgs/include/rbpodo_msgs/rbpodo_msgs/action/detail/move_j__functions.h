// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rbpodo_msgs:action/MoveJ.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__ACTION__DETAIL__MOVE_J__FUNCTIONS_H_
#define RBPODO_MSGS__ACTION__DETAIL__MOVE_J__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rbpodo_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rbpodo_msgs/action/detail/move_j__struct.h"

/// Initialize action/MoveJ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__action__MoveJ_Goal
 * )) before or use
 * rbpodo_msgs__action__MoveJ_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Goal__init(rbpodo_msgs__action__MoveJ_Goal * msg);

/// Finalize action/MoveJ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Goal__fini(rbpodo_msgs__action__MoveJ_Goal * msg);

/// Create action/MoveJ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__action__MoveJ_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_Goal *
rbpodo_msgs__action__MoveJ_Goal__create();

/// Destroy action/MoveJ message.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Goal__destroy(rbpodo_msgs__action__MoveJ_Goal * msg);

/// Check for action/MoveJ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Goal__are_equal(const rbpodo_msgs__action__MoveJ_Goal * lhs, const rbpodo_msgs__action__MoveJ_Goal * rhs);

/// Copy a action/MoveJ message.
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
rbpodo_msgs__action__MoveJ_Goal__copy(
  const rbpodo_msgs__action__MoveJ_Goal * input,
  rbpodo_msgs__action__MoveJ_Goal * output);

/// Initialize array of action/MoveJ messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__action__MoveJ_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Goal__Sequence__init(rbpodo_msgs__action__MoveJ_Goal__Sequence * array, size_t size);

/// Finalize array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Goal__Sequence__fini(rbpodo_msgs__action__MoveJ_Goal__Sequence * array);

/// Create array of action/MoveJ messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__action__MoveJ_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_Goal__Sequence *
rbpodo_msgs__action__MoveJ_Goal__Sequence__create(size_t size);

/// Destroy array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Goal__Sequence__destroy(rbpodo_msgs__action__MoveJ_Goal__Sequence * array);

/// Check for action/MoveJ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Goal__Sequence__are_equal(const rbpodo_msgs__action__MoveJ_Goal__Sequence * lhs, const rbpodo_msgs__action__MoveJ_Goal__Sequence * rhs);

/// Copy an array of action/MoveJ messages.
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
rbpodo_msgs__action__MoveJ_Goal__Sequence__copy(
  const rbpodo_msgs__action__MoveJ_Goal__Sequence * input,
  rbpodo_msgs__action__MoveJ_Goal__Sequence * output);

/// Initialize action/MoveJ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__action__MoveJ_Result
 * )) before or use
 * rbpodo_msgs__action__MoveJ_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Result__init(rbpodo_msgs__action__MoveJ_Result * msg);

/// Finalize action/MoveJ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Result__fini(rbpodo_msgs__action__MoveJ_Result * msg);

/// Create action/MoveJ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__action__MoveJ_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_Result *
rbpodo_msgs__action__MoveJ_Result__create();

/// Destroy action/MoveJ message.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Result__destroy(rbpodo_msgs__action__MoveJ_Result * msg);

/// Check for action/MoveJ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Result__are_equal(const rbpodo_msgs__action__MoveJ_Result * lhs, const rbpodo_msgs__action__MoveJ_Result * rhs);

/// Copy a action/MoveJ message.
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
rbpodo_msgs__action__MoveJ_Result__copy(
  const rbpodo_msgs__action__MoveJ_Result * input,
  rbpodo_msgs__action__MoveJ_Result * output);

/// Initialize array of action/MoveJ messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__action__MoveJ_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Result__Sequence__init(rbpodo_msgs__action__MoveJ_Result__Sequence * array, size_t size);

/// Finalize array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Result__Sequence__fini(rbpodo_msgs__action__MoveJ_Result__Sequence * array);

/// Create array of action/MoveJ messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__action__MoveJ_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_Result__Sequence *
rbpodo_msgs__action__MoveJ_Result__Sequence__create(size_t size);

/// Destroy array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Result__Sequence__destroy(rbpodo_msgs__action__MoveJ_Result__Sequence * array);

/// Check for action/MoveJ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Result__Sequence__are_equal(const rbpodo_msgs__action__MoveJ_Result__Sequence * lhs, const rbpodo_msgs__action__MoveJ_Result__Sequence * rhs);

/// Copy an array of action/MoveJ messages.
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
rbpodo_msgs__action__MoveJ_Result__Sequence__copy(
  const rbpodo_msgs__action__MoveJ_Result__Sequence * input,
  rbpodo_msgs__action__MoveJ_Result__Sequence * output);

/// Initialize action/MoveJ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__action__MoveJ_Feedback
 * )) before or use
 * rbpodo_msgs__action__MoveJ_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Feedback__init(rbpodo_msgs__action__MoveJ_Feedback * msg);

/// Finalize action/MoveJ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Feedback__fini(rbpodo_msgs__action__MoveJ_Feedback * msg);

/// Create action/MoveJ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__action__MoveJ_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_Feedback *
rbpodo_msgs__action__MoveJ_Feedback__create();

/// Destroy action/MoveJ message.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Feedback__destroy(rbpodo_msgs__action__MoveJ_Feedback * msg);

/// Check for action/MoveJ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Feedback__are_equal(const rbpodo_msgs__action__MoveJ_Feedback * lhs, const rbpodo_msgs__action__MoveJ_Feedback * rhs);

/// Copy a action/MoveJ message.
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
rbpodo_msgs__action__MoveJ_Feedback__copy(
  const rbpodo_msgs__action__MoveJ_Feedback * input,
  rbpodo_msgs__action__MoveJ_Feedback * output);

/// Initialize array of action/MoveJ messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__action__MoveJ_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Feedback__Sequence__init(rbpodo_msgs__action__MoveJ_Feedback__Sequence * array, size_t size);

/// Finalize array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Feedback__Sequence__fini(rbpodo_msgs__action__MoveJ_Feedback__Sequence * array);

/// Create array of action/MoveJ messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__action__MoveJ_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_Feedback__Sequence *
rbpodo_msgs__action__MoveJ_Feedback__Sequence__create(size_t size);

/// Destroy array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_Feedback__Sequence__destroy(rbpodo_msgs__action__MoveJ_Feedback__Sequence * array);

/// Check for action/MoveJ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_Feedback__Sequence__are_equal(const rbpodo_msgs__action__MoveJ_Feedback__Sequence * lhs, const rbpodo_msgs__action__MoveJ_Feedback__Sequence * rhs);

/// Copy an array of action/MoveJ messages.
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
rbpodo_msgs__action__MoveJ_Feedback__Sequence__copy(
  const rbpodo_msgs__action__MoveJ_Feedback__Sequence * input,
  rbpodo_msgs__action__MoveJ_Feedback__Sequence * output);

/// Initialize action/MoveJ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__action__MoveJ_SendGoal_Request
 * )) before or use
 * rbpodo_msgs__action__MoveJ_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_SendGoal_Request__init(rbpodo_msgs__action__MoveJ_SendGoal_Request * msg);

/// Finalize action/MoveJ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_SendGoal_Request__fini(rbpodo_msgs__action__MoveJ_SendGoal_Request * msg);

/// Create action/MoveJ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_SendGoal_Request *
rbpodo_msgs__action__MoveJ_SendGoal_Request__create();

/// Destroy action/MoveJ message.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_SendGoal_Request__destroy(rbpodo_msgs__action__MoveJ_SendGoal_Request * msg);

/// Check for action/MoveJ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_SendGoal_Request__are_equal(const rbpodo_msgs__action__MoveJ_SendGoal_Request * lhs, const rbpodo_msgs__action__MoveJ_SendGoal_Request * rhs);

/// Copy a action/MoveJ message.
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
rbpodo_msgs__action__MoveJ_SendGoal_Request__copy(
  const rbpodo_msgs__action__MoveJ_SendGoal_Request * input,
  rbpodo_msgs__action__MoveJ_SendGoal_Request * output);

/// Initialize array of action/MoveJ messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence__init(rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence__fini(rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence * array);

/// Create array of action/MoveJ messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence *
rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence__destroy(rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence * array);

/// Check for action/MoveJ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence__are_equal(const rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence * lhs, const rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/MoveJ messages.
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
rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence__copy(
  const rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence * input,
  rbpodo_msgs__action__MoveJ_SendGoal_Request__Sequence * output);

/// Initialize action/MoveJ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__action__MoveJ_SendGoal_Response
 * )) before or use
 * rbpodo_msgs__action__MoveJ_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_SendGoal_Response__init(rbpodo_msgs__action__MoveJ_SendGoal_Response * msg);

/// Finalize action/MoveJ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_SendGoal_Response__fini(rbpodo_msgs__action__MoveJ_SendGoal_Response * msg);

/// Create action/MoveJ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_SendGoal_Response *
rbpodo_msgs__action__MoveJ_SendGoal_Response__create();

/// Destroy action/MoveJ message.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_SendGoal_Response__destroy(rbpodo_msgs__action__MoveJ_SendGoal_Response * msg);

/// Check for action/MoveJ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_SendGoal_Response__are_equal(const rbpodo_msgs__action__MoveJ_SendGoal_Response * lhs, const rbpodo_msgs__action__MoveJ_SendGoal_Response * rhs);

/// Copy a action/MoveJ message.
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
rbpodo_msgs__action__MoveJ_SendGoal_Response__copy(
  const rbpodo_msgs__action__MoveJ_SendGoal_Response * input,
  rbpodo_msgs__action__MoveJ_SendGoal_Response * output);

/// Initialize array of action/MoveJ messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence__init(rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence__fini(rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence * array);

/// Create array of action/MoveJ messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence *
rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence__destroy(rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence * array);

/// Check for action/MoveJ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence__are_equal(const rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence * lhs, const rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/MoveJ messages.
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
rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence__copy(
  const rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence * input,
  rbpodo_msgs__action__MoveJ_SendGoal_Response__Sequence * output);

/// Initialize action/MoveJ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__action__MoveJ_GetResult_Request
 * )) before or use
 * rbpodo_msgs__action__MoveJ_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_GetResult_Request__init(rbpodo_msgs__action__MoveJ_GetResult_Request * msg);

/// Finalize action/MoveJ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_GetResult_Request__fini(rbpodo_msgs__action__MoveJ_GetResult_Request * msg);

/// Create action/MoveJ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__action__MoveJ_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_GetResult_Request *
rbpodo_msgs__action__MoveJ_GetResult_Request__create();

/// Destroy action/MoveJ message.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_GetResult_Request__destroy(rbpodo_msgs__action__MoveJ_GetResult_Request * msg);

/// Check for action/MoveJ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_GetResult_Request__are_equal(const rbpodo_msgs__action__MoveJ_GetResult_Request * lhs, const rbpodo_msgs__action__MoveJ_GetResult_Request * rhs);

/// Copy a action/MoveJ message.
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
rbpodo_msgs__action__MoveJ_GetResult_Request__copy(
  const rbpodo_msgs__action__MoveJ_GetResult_Request * input,
  rbpodo_msgs__action__MoveJ_GetResult_Request * output);

/// Initialize array of action/MoveJ messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__action__MoveJ_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence__init(rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence__fini(rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence * array);

/// Create array of action/MoveJ messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence *
rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence__destroy(rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence * array);

/// Check for action/MoveJ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence__are_equal(const rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence * lhs, const rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence * rhs);

/// Copy an array of action/MoveJ messages.
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
rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence__copy(
  const rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence * input,
  rbpodo_msgs__action__MoveJ_GetResult_Request__Sequence * output);

/// Initialize action/MoveJ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__action__MoveJ_GetResult_Response
 * )) before or use
 * rbpodo_msgs__action__MoveJ_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_GetResult_Response__init(rbpodo_msgs__action__MoveJ_GetResult_Response * msg);

/// Finalize action/MoveJ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_GetResult_Response__fini(rbpodo_msgs__action__MoveJ_GetResult_Response * msg);

/// Create action/MoveJ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__action__MoveJ_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_GetResult_Response *
rbpodo_msgs__action__MoveJ_GetResult_Response__create();

/// Destroy action/MoveJ message.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_GetResult_Response__destroy(rbpodo_msgs__action__MoveJ_GetResult_Response * msg);

/// Check for action/MoveJ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_GetResult_Response__are_equal(const rbpodo_msgs__action__MoveJ_GetResult_Response * lhs, const rbpodo_msgs__action__MoveJ_GetResult_Response * rhs);

/// Copy a action/MoveJ message.
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
rbpodo_msgs__action__MoveJ_GetResult_Response__copy(
  const rbpodo_msgs__action__MoveJ_GetResult_Response * input,
  rbpodo_msgs__action__MoveJ_GetResult_Response * output);

/// Initialize array of action/MoveJ messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__action__MoveJ_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence__init(rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence__fini(rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence * array);

/// Create array of action/MoveJ messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence *
rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence__destroy(rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence * array);

/// Check for action/MoveJ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence__are_equal(const rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence * lhs, const rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence * rhs);

/// Copy an array of action/MoveJ messages.
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
rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence__copy(
  const rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence * input,
  rbpodo_msgs__action__MoveJ_GetResult_Response__Sequence * output);

/// Initialize action/MoveJ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__action__MoveJ_FeedbackMessage
 * )) before or use
 * rbpodo_msgs__action__MoveJ_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_FeedbackMessage__init(rbpodo_msgs__action__MoveJ_FeedbackMessage * msg);

/// Finalize action/MoveJ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_FeedbackMessage__fini(rbpodo_msgs__action__MoveJ_FeedbackMessage * msg);

/// Create action/MoveJ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__action__MoveJ_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_FeedbackMessage *
rbpodo_msgs__action__MoveJ_FeedbackMessage__create();

/// Destroy action/MoveJ message.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_FeedbackMessage__destroy(rbpodo_msgs__action__MoveJ_FeedbackMessage * msg);

/// Check for action/MoveJ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_FeedbackMessage__are_equal(const rbpodo_msgs__action__MoveJ_FeedbackMessage * lhs, const rbpodo_msgs__action__MoveJ_FeedbackMessage * rhs);

/// Copy a action/MoveJ message.
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
rbpodo_msgs__action__MoveJ_FeedbackMessage__copy(
  const rbpodo_msgs__action__MoveJ_FeedbackMessage * input,
  rbpodo_msgs__action__MoveJ_FeedbackMessage * output);

/// Initialize array of action/MoveJ messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__action__MoveJ_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence__init(rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence__fini(rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence * array);

/// Create array of action/MoveJ messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence *
rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/MoveJ messages.
/**
 * It calls
 * rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence__destroy(rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence * array);

/// Check for action/MoveJ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence__are_equal(const rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence * lhs, const rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/MoveJ messages.
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
rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence__copy(
  const rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence * input,
  rbpodo_msgs__action__MoveJ_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__ACTION__DETAIL__MOVE_J__FUNCTIONS_H_
