// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:action/MoveJb2.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__ACTION__DETAIL__MOVE_JB2__STRUCT_H_
#define RBPODO_MSGS__ACTION__DETAIL__MOVE_JB2__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'points'
#include "rbpodo_msgs/msg/detail/move_jb2_point__struct.h"

/// Struct defined in action/MoveJb2 in the package rbpodo_msgs.
typedef struct rbpodo_msgs__action__MoveJb2_Goal
{
  rbpodo_msgs__msg__MoveJb2Point__Sequence points;
  /// maximum duration (in seconds) to wait for start signal before timing out.
  float time_for_waiting_start;
} rbpodo_msgs__action__MoveJb2_Goal;

// Struct for a sequence of rbpodo_msgs__action__MoveJb2_Goal.
typedef struct rbpodo_msgs__action__MoveJb2_Goal__Sequence
{
  rbpodo_msgs__action__MoveJb2_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__action__MoveJb2_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/MoveJb2 in the package rbpodo_msgs.
typedef struct rbpodo_msgs__action__MoveJb2_Result
{
  bool success;
} rbpodo_msgs__action__MoveJb2_Result;

// Struct for a sequence of rbpodo_msgs__action__MoveJb2_Result.
typedef struct rbpodo_msgs__action__MoveJb2_Result__Sequence
{
  rbpodo_msgs__action__MoveJb2_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__action__MoveJb2_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'state'
#include "rbpodo_msgs/msg/detail/system_state__struct.h"

/// Struct defined in action/MoveJb2 in the package rbpodo_msgs.
typedef struct rbpodo_msgs__action__MoveJb2_Feedback
{
  rbpodo_msgs__msg__SystemState state;
} rbpodo_msgs__action__MoveJb2_Feedback;

// Struct for a sequence of rbpodo_msgs__action__MoveJb2_Feedback.
typedef struct rbpodo_msgs__action__MoveJb2_Feedback__Sequence
{
  rbpodo_msgs__action__MoveJb2_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__action__MoveJb2_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "rbpodo_msgs/action/detail/move_jb2__struct.h"

/// Struct defined in action/MoveJb2 in the package rbpodo_msgs.
typedef struct rbpodo_msgs__action__MoveJb2_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  rbpodo_msgs__action__MoveJb2_Goal goal;
} rbpodo_msgs__action__MoveJb2_SendGoal_Request;

// Struct for a sequence of rbpodo_msgs__action__MoveJb2_SendGoal_Request.
typedef struct rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence
{
  rbpodo_msgs__action__MoveJb2_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MoveJb2 in the package rbpodo_msgs.
typedef struct rbpodo_msgs__action__MoveJb2_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} rbpodo_msgs__action__MoveJb2_SendGoal_Response;

// Struct for a sequence of rbpodo_msgs__action__MoveJb2_SendGoal_Response.
typedef struct rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence
{
  rbpodo_msgs__action__MoveJb2_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MoveJb2 in the package rbpodo_msgs.
typedef struct rbpodo_msgs__action__MoveJb2_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} rbpodo_msgs__action__MoveJb2_GetResult_Request;

// Struct for a sequence of rbpodo_msgs__action__MoveJb2_GetResult_Request.
typedef struct rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence
{
  rbpodo_msgs__action__MoveJb2_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rbpodo_msgs/action/detail/move_jb2__struct.h"

/// Struct defined in action/MoveJb2 in the package rbpodo_msgs.
typedef struct rbpodo_msgs__action__MoveJb2_GetResult_Response
{
  int8_t status;
  rbpodo_msgs__action__MoveJb2_Result result;
} rbpodo_msgs__action__MoveJb2_GetResult_Response;

// Struct for a sequence of rbpodo_msgs__action__MoveJb2_GetResult_Response.
typedef struct rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence
{
  rbpodo_msgs__action__MoveJb2_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "rbpodo_msgs/action/detail/move_jb2__struct.h"

/// Struct defined in action/MoveJb2 in the package rbpodo_msgs.
typedef struct rbpodo_msgs__action__MoveJb2_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  rbpodo_msgs__action__MoveJb2_Feedback feedback;
} rbpodo_msgs__action__MoveJb2_FeedbackMessage;

// Struct for a sequence of rbpodo_msgs__action__MoveJb2_FeedbackMessage.
typedef struct rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence
{
  rbpodo_msgs__action__MoveJb2_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__ACTION__DETAIL__MOVE_JB2__STRUCT_H_
