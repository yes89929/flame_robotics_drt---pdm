// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rbpodo_msgs:srv/SetJointEffortControllerConfig.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rbpodo_msgs/srv/detail/set_joint_effort_controller_config__rosidl_typesupport_introspection_c.h"
#include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rbpodo_msgs/srv/detail/set_joint_effort_controller_config__functions.h"
#include "rbpodo_msgs/srv/detail/set_joint_effort_controller_config__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__init(message_memory);
}

void rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_fini_function(void * message_memory)
{
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_member_array[3] = {
  {
    "t1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__srv__SetJointEffortControllerConfig_Request, t1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "t2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__srv__SetJointEffortControllerConfig_Request, t2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__srv__SetJointEffortControllerConfig_Request, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_members = {
  "rbpodo_msgs__srv",  // message namespace
  "SetJointEffortControllerConfig_Request",  // message name
  3,  // number of fields
  sizeof(rbpodo_msgs__srv__SetJointEffortControllerConfig_Request),
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_member_array,  // message members
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_type_support_handle = {
  0,
  &rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, srv, SetJointEffortControllerConfig_Request)() {
  if (!rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__srv__SetJointEffortControllerConfig_Request__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "rbpodo_msgs/srv/detail/set_joint_effort_controller_config__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "rbpodo_msgs/srv/detail/set_joint_effort_controller_config__functions.h"
// already included above
// #include "rbpodo_msgs/srv/detail/set_joint_effort_controller_config__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__init(message_memory);
}

void rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_fini_function(void * message_memory)
{
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs__srv__SetJointEffortControllerConfig_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_members = {
  "rbpodo_msgs__srv",  // message namespace
  "SetJointEffortControllerConfig_Response",  // message name
  1,  // number of fields
  sizeof(rbpodo_msgs__srv__SetJointEffortControllerConfig_Response),
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_member_array,  // message members
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_type_support_handle = {
  0,
  &rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, srv, SetJointEffortControllerConfig_Response)() {
  if (!rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rbpodo_msgs__srv__SetJointEffortControllerConfig_Response__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rbpodo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rbpodo_msgs/srv/detail/set_joint_effort_controller_config__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_service_members = {
  "rbpodo_msgs__srv",  // service namespace
  "SetJointEffortControllerConfig",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Request_message_type_support_handle,
  NULL  // response message
  // rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_Response_message_type_support_handle
};

static rosidl_service_type_support_t rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_service_type_support_handle = {
  0,
  &rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, srv, SetJointEffortControllerConfig_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, srv, SetJointEffortControllerConfig_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rbpodo_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, srv, SetJointEffortControllerConfig)() {
  if (!rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_service_type_support_handle.typesupport_identifier) {
    rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, srv, SetJointEffortControllerConfig_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rbpodo_msgs, srv, SetJointEffortControllerConfig_Response)()->data;
  }

  return &rbpodo_msgs__srv__detail__set_joint_effort_controller_config__rosidl_typesupport_introspection_c__SetJointEffortControllerConfig_service_type_support_handle;
}
