// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rbpodo_msgs:action/MoveL.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
#include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rbpodo_msgs/action/detail/move_l__functions.h"
#include "rbpodo_msgs/action/detail/move_l__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__action__MoveL_Goal__init(message_memory);
}

void rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_fini_function(void * message_memory)
{
  rbpodo_msgs__action__MoveL_Goal__fini(message_memory);
}

size_t rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__size_function__MoveL_Goal__point(
  const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveL_Goal__point(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__get_function__MoveL_Goal__point(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__fetch_function__MoveL_Goal__point(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveL_Goal__point(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__assign_function__MoveL_Goal__point(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__get_function__MoveL_Goal__point(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_message_member_array[4] = {
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_Goal, point),  // bytes offset in struct
    NULL,  // default value
    rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__size_function__MoveL_Goal__point,  // size() function pointer
    rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__get_const_function__MoveL_Goal__point,  // get_const(index) function pointer
    rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__get_function__MoveL_Goal__point,  // get(index) function pointer
    rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__fetch_function__MoveL_Goal__point,  // fetch(index, &value) function pointer
    rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__assign_function__MoveL_Goal__point,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_Goal, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceleration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_Goal, acceleration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time_for_waiting_start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_Goal, time_for_waiting_start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_message_members = {
  "rbpodo_msgs__action",  // message namespace
  "MoveL_Goal",  // message name
  4,  // number of fields
  sizeof(rbpodo_msgs__action__MoveL_Goal),
  rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_message_member_array,  // message members
  rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_message_type_support_handle = {
  0,
  &rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_Goal)() {
  if (!rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__action__MoveL_Goal__rosidl_typesupport_introspection_c__MoveL_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__functions.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__action__MoveL_Result__init(message_memory);
}

void rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_fini_function(void * message_memory)
{
  rbpodo_msgs__action__MoveL_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_message_members = {
  "rbpodo_msgs__action",  // message namespace
  "MoveL_Result",  // message name
  1,  // number of fields
  sizeof(rbpodo_msgs__action__MoveL_Result),
  rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_message_member_array,  // message members
  rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_message_type_support_handle = {
  0,
  &rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_Result)() {
  if (!rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__action__MoveL_Result__rosidl_typesupport_introspection_c__MoveL_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__functions.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__struct.h"


// Include directives for member types
// Member `state`
#include "rbpodo_msgs/msg/system_state.h"
// Member `state`
#include "rbpodo_msgs/msg/detail/system_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__action__MoveL_Feedback__init(message_memory);
}

void rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_fini_function(void * message_memory)
{
  rbpodo_msgs__action__MoveL_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_member_array[1] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_Feedback, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_members = {
  "rbpodo_msgs__action",  // message namespace
  "MoveL_Feedback",  // message name
  1,  // number of fields
  sizeof(rbpodo_msgs__action__MoveL_Feedback),
  rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_member_array,  // message members
  rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_type_support_handle = {
  0,
  &rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_Feedback)() {
  rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, msg, SystemState)();
  if (!rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__action__MoveL_Feedback__rosidl_typesupport_introspection_c__MoveL_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__functions.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "rbpodo_msgs/action/move_l.h"
// Member `goal`
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__action__MoveL_SendGoal_Request__init(message_memory);
}

void rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_fini_function(void * message_memory)
{
  rbpodo_msgs__action__MoveL_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_members = {
  "rbpodo_msgs__action",  // message namespace
  "MoveL_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(rbpodo_msgs__action__MoveL_SendGoal_Request),
  rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_member_array,  // message members
  rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_type_support_handle = {
  0,
  &rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_SendGoal_Request)() {
  rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_Goal)();
  if (!rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__action__MoveL_SendGoal_Request__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__functions.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__action__MoveL_SendGoal_Response__init(message_memory);
}

void rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_fini_function(void * message_memory)
{
  rbpodo_msgs__action__MoveL_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_members = {
  "rbpodo_msgs__action",  // message namespace
  "MoveL_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(rbpodo_msgs__action__MoveL_SendGoal_Response),
  rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_member_array,  // message members
  rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_type_support_handle = {
  0,
  &rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_SendGoal_Response)() {
  rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__action__MoveL_SendGoal_Response__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_service_members = {
  "rbpodo_msgs__action",  // service namespace
  "MoveL_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_service_type_support_handle = {
  0,
  &rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_SendGoal)() {
  if (!rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_service_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_SendGoal_Response)()->data;
  }

  return &rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__functions.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__action__MoveL_GetResult_Request__init(message_memory);
}

void rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_fini_function(void * message_memory)
{
  rbpodo_msgs__action__MoveL_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_members = {
  "rbpodo_msgs__action",  // message namespace
  "MoveL_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(rbpodo_msgs__action__MoveL_GetResult_Request),
  rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_member_array,  // message members
  rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_type_support_handle = {
  0,
  &rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_GetResult_Request)() {
  rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__action__MoveL_GetResult_Request__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__functions.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "rbpodo_msgs/action/move_l.h"
// Member `result`
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__action__MoveL_GetResult_Response__init(message_memory);
}

void rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_fini_function(void * message_memory)
{
  rbpodo_msgs__action__MoveL_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_members = {
  "rbpodo_msgs__action",  // message namespace
  "MoveL_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(rbpodo_msgs__action__MoveL_GetResult_Response),
  rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_member_array,  // message members
  rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_type_support_handle = {
  0,
  &rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_GetResult_Response)() {
  rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_Result)();
  if (!rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__action__MoveL_GetResult_Response__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_service_members = {
  "rbpodo_msgs__action",  // service namespace
  "MoveL_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_service_type_support_handle = {
  0,
  &rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_GetResult)() {
  if (!rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_service_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_GetResult_Response)()->data;
  }

  return &rbpodo_msgs__action__detail__move_l__rosidl_typesupport_introspection_c__MoveL_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__functions.h"
// already included above
// #include "rbpodo_msgs/action/detail/move_l__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "rbpodo_msgs/action/move_l.h"
// Member `feedback`
// already included above
// #include "rbpodo_msgs/action/detail/move_l__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__action__MoveL_FeedbackMessage__init(message_memory);
}

void rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_fini_function(void * message_memory)
{
  rbpodo_msgs__action__MoveL_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__action__MoveL_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_members = {
  "rbpodo_msgs__action",  // message namespace
  "MoveL_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(rbpodo_msgs__action__MoveL_FeedbackMessage),
  rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_member_array,  // message members
  rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_type_support_handle = {
  0,
  &rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_FeedbackMessage)() {
  rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, action, MoveL_Feedback)();
  if (!rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__action__MoveL_FeedbackMessage__rosidl_typesupport_introspection_c__MoveL_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
