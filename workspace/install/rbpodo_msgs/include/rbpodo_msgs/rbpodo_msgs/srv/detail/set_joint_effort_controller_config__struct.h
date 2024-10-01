// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:srv/SetJointEffortControllerConfig.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__SET_JOINT_EFFORT_CONTROLLER_CONFIG__STRUCT_H_
#define RBPODO_MSGS__SRV__DETAIL__SET_JOINT_EFFORT_CONTROLLER_CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetJointEffortControllerConfig in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__SetJointEffortControllerConfig_Request
{
  double t1;
  /// Time to maintain the action after arrival (unit: sec. 0.02 < t2 < 0.2)
  double t2;
  /// Compensation mode
  /// 0: target effort = input effort
  /// 1: target effort = input effort + gravity compensation value
  /// 2: target effort = input effort + friction compensation value 30%
  /// 3: target effort = input effort + gravity compensation value + frcition compensation value 30%
  uint8_t mode;
} rbpodo_msgs__srv__SetJointEffortControllerConfig_Request;

// Struct for a sequence of rbpodo_msgs__srv__SetJointEffortControllerConfig_Request.
typedef struct rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__Sequence
{
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetJointEffortControllerConfig in the package rbpodo_msgs.
typedef struct rbpodo_msgs__srv__SetJointEffortControllerConfig_Response
{
  bool success;
} rbpodo_msgs__srv__SetJointEffortControllerConfig_Response;

// Struct for a sequence of rbpodo_msgs__srv__SetJointEffortControllerConfig_Response.
typedef struct rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__Sequence
{
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__SRV__DETAIL__SET_JOINT_EFFORT_CONTROLLER_CONFIG__STRUCT_H_
