// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rbpodo_msgs:srv/SetJointVelocityControllerConfig.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__SET_JOINT_VELOCITY_CONTROLLER_CONFIG__FUNCTIONS_H_
#define RBPODO_MSGS__SRV__DETAIL__SET_JOINT_VELOCITY_CONTROLLER_CONFIG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rbpodo_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "rbpodo_msgs/srv/detail/set_joint_velocity_controller_config__struct.h"

/// Initialize srv/SetJointVelocityControllerConfig message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request
 * )) before or use
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__init(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * msg);

/// Finalize srv/SetJointVelocityControllerConfig message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__fini(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * msg);

/// Create srv/SetJointVelocityControllerConfig message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request *
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__create();

/// Destroy srv/SetJointVelocityControllerConfig message.
/**
 * It calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__destroy(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * msg);

/// Check for srv/SetJointVelocityControllerConfig message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__are_equal(const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * lhs, const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * rhs);

/// Copy a srv/SetJointVelocityControllerConfig message.
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
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__copy(
  const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * input,
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * output);

/// Initialize array of srv/SetJointVelocityControllerConfig messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__init(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * array, size_t size);

/// Finalize array of srv/SetJointVelocityControllerConfig messages.
/**
 * It calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__fini(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * array);

/// Create array of srv/SetJointVelocityControllerConfig messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence *
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__create(size_t size);

/// Destroy array of srv/SetJointVelocityControllerConfig messages.
/**
 * It calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__destroy(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * array);

/// Check for srv/SetJointVelocityControllerConfig message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__are_equal(const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * lhs, const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * rhs);

/// Copy an array of srv/SetJointVelocityControllerConfig messages.
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
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__copy(
  const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * input,
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * output);

/// Initialize srv/SetJointVelocityControllerConfig message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response
 * )) before or use
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__init(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * msg);

/// Finalize srv/SetJointVelocityControllerConfig message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__fini(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * msg);

/// Create srv/SetJointVelocityControllerConfig message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response *
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__create();

/// Destroy srv/SetJointVelocityControllerConfig message.
/**
 * It calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__destroy(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * msg);

/// Check for srv/SetJointVelocityControllerConfig message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__are_equal(const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * lhs, const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * rhs);

/// Copy a srv/SetJointVelocityControllerConfig message.
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
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__copy(
  const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * input,
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * output);

/// Initialize array of srv/SetJointVelocityControllerConfig messages.
/**
 * It allocates the memory for the number of elements and calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__init(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * array, size_t size);

/// Finalize array of srv/SetJointVelocityControllerConfig messages.
/**
 * It calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__fini(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * array);

/// Create array of srv/SetJointVelocityControllerConfig messages.
/**
 * It allocates the memory for the array and calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence *
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__create(size_t size);

/// Destroy array of srv/SetJointVelocityControllerConfig messages.
/**
 * It calls
 * rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__destroy(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * array);

/// Check for srv/SetJointVelocityControllerConfig message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rbpodo_msgs
bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__are_equal(const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * lhs, const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * rhs);

/// Copy an array of srv/SetJointVelocityControllerConfig messages.
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
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__copy(
  const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * input,
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__SRV__DETAIL__SET_JOINT_VELOCITY_CONTROLLER_CONFIG__FUNCTIONS_H_
