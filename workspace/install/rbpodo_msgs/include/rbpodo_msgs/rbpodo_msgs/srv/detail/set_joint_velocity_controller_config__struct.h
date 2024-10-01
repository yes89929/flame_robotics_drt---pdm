// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:srv/SetJointVelocityControllerConfig.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__SET_JOINT_VELOCITY_CONTROLLER_CONFIG__STRUCT_H_
#define RBPODO_MSGS__SRV__DETAIL__SET_JOINT_VELOCITY_CONTROLLER_CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetJointVelocityControllerConfig in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request
{
  double t1;
  /// Time to maintain the action after arrival (unit: sec. 0.02 < t2 < 0.2)
  double t2;
  /// Speed tracking rate (gain > 0)
  double gain;
  /// Low-pass filter gain (The smaller it is, the smoother the action becomes. 0 < alpha < 1)
  double alpha;
} rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request;

// Struct for a sequence of rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request.
typedef struct rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence
{
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetJointVelocityControllerConfig in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response
{
  bool success;
} rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response;

// Struct for a sequence of rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response.
typedef struct rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence
{
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__SRV__DETAIL__SET_JOINT_VELOCITY_CONTROLLER_CONFIG__STRUCT_H_
