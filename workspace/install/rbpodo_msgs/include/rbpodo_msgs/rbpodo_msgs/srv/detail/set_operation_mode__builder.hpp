// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:srv/SetOperationMode.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__SET_OPERATION_MODE__BUILDER_HPP_
#define RBPODO_MSGS__SRV__DETAIL__SET_OPERATION_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/srv/detail/set_operation_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_SetOperationMode_Request_mode
{
public:
  Init_SetOperationMode_Request_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::SetOperationMode_Request mode(::rbpodo_msgs::srv::SetOperationMode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetOperationMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::SetOperationMode_Request>()
{
  return rbpodo_msgs::srv::builder::Init_SetOperationMode_Request_mode();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_SetOperationMode_Response_success
{
public:
  Init_SetOperationMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::SetOperationMode_Response success(::rbpodo_msgs::srv::SetOperationMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetOperationMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::SetOperationMode_Response>()
{
  return rbpodo_msgs::srv::builder::Init_SetOperationMode_Response_success();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__SRV__DETAIL__SET_OPERATION_MODE__BUILDER_HPP_
