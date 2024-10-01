// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rbpodo_msgs:srv/SetCartesianPoseControllerConfig.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rbpodo_msgs/srv/detail/set_cartesian_pose_controller_config__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rbpodo_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void SetCartesianPoseControllerConfig_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request(_init);
}

void SetCartesianPoseControllerConfig_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request *>(message_memory);
  typed_message->~SetCartesianPoseControllerConfig_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SetCartesianPoseControllerConfig_Request_message_member_array[4] = {
  {
    "t1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request, t1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "t2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request, t2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gain",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request, gain),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "alpha",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request, alpha),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SetCartesianPoseControllerConfig_Request_message_members = {
  "rbpodo_msgs::srv",  // message namespace
  "SetCartesianPoseControllerConfig_Request",  // message name
  4,  // number of fields
  sizeof(rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request),
  SetCartesianPoseControllerConfig_Request_message_member_array,  // message members
  SetCartesianPoseControllerConfig_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  SetCartesianPoseControllerConfig_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SetCartesianPoseControllerConfig_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SetCartesianPoseControllerConfig_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rbpodo_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request>()
{
  return &::rbpodo_msgs::srv::rosidl_typesupport_introspection_cpp::SetCartesianPoseControllerConfig_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rbpodo_msgs, srv, SetCartesianPoseControllerConfig_Request)() {
  return &::rbpodo_msgs::srv::rosidl_typesupport_introspection_cpp::SetCartesianPoseControllerConfig_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rbpodo_msgs/srv/detail/set_cartesian_pose_controller_config__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rbpodo_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void SetCartesianPoseControllerConfig_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response(_init);
}

void SetCartesianPoseControllerConfig_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response *>(message_memory);
  typed_message->~SetCartesianPoseControllerConfig_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SetCartesianPoseControllerConfig_Response_message_member_array[1] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SetCartesianPoseControllerConfig_Response_message_members = {
  "rbpodo_msgs::srv",  // message namespace
  "SetCartesianPoseControllerConfig_Response",  // message name
  1,  // number of fields
  sizeof(rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response),
  SetCartesianPoseControllerConfig_Response_message_member_array,  // message members
  SetCartesianPoseControllerConfig_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  SetCartesianPoseControllerConfig_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SetCartesianPoseControllerConfig_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SetCartesianPoseControllerConfig_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rbpodo_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response>()
{
  return &::rbpodo_msgs::srv::rosidl_typesupport_introspection_cpp::SetCartesianPoseControllerConfig_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rbpodo_msgs, srv, SetCartesianPoseControllerConfig_Response)() {
  return &::rbpodo_msgs::srv::rosidl_typesupport_introspection_cpp::SetCartesianPoseControllerConfig_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "rbpodo_msgs/srv/detail/set_cartesian_pose_controller_config__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace rbpodo_msgs
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers SetCartesianPoseControllerConfig_service_members = {
  "rbpodo_msgs::srv",  // service namespace
  "SetCartesianPoseControllerConfig",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<rbpodo_msgs::srv::SetCartesianPoseControllerConfig>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t SetCartesianPoseControllerConfig_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SetCartesianPoseControllerConfig_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace rbpodo_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<rbpodo_msgs::srv::SetCartesianPoseControllerConfig>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::rbpodo_msgs::srv::rosidl_typesupport_introspection_cpp::SetCartesianPoseControllerConfig_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rbpodo_msgs, srv, SetCartesianPoseControllerConfig)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<rbpodo_msgs::srv::SetCartesianPoseControllerConfig>();
}

#ifdef __cplusplus
}
#endif
