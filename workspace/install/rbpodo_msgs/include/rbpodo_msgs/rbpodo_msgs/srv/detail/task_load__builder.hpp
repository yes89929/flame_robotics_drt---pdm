// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:srv/TaskLoad.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__BUILDER_HPP_
#define RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/srv/detail/task_load__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskLoad_Request_timeout
{
public:
  explicit Init_TaskLoad_Request_timeout(::rbpodo_msgs::srv::TaskLoad_Request & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::srv::TaskLoad_Request timeout(::rbpodo_msgs::srv::TaskLoad_Request::_timeout_type arg)
  {
    msg_.timeout = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::TaskLoad_Request msg_;
};

class Init_TaskLoad_Request_program_name
{
public:
  Init_TaskLoad_Request_program_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskLoad_Request_timeout program_name(::rbpodo_msgs::srv::TaskLoad_Request::_program_name_type arg)
  {
    msg_.program_name = std::move(arg);
    return Init_TaskLoad_Request_timeout(msg_);
  }

private:
  ::rbpodo_msgs::srv::TaskLoad_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::TaskLoad_Request>()
{
  return rbpodo_msgs::srv::builder::Init_TaskLoad_Request_program_name();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskLoad_Response_success
{
public:
  Init_TaskLoad_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::TaskLoad_Response success(::rbpodo_msgs::srv::TaskLoad_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::TaskLoad_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::TaskLoad_Response>()
{
  return rbpodo_msgs::srv::builder::Init_TaskLoad_Response_success();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__BUILDER_HPP_
