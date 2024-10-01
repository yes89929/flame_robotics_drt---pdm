// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:srv/TaskPause.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__TASK_PAUSE__BUILDER_HPP_
#define RBPODO_MSGS__SRV__DETAIL__TASK_PAUSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/srv/detail/task_pause__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::TaskPause_Request>()
{
  return ::rbpodo_msgs::srv::TaskPause_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskPause_Response_success
{
public:
  Init_TaskPause_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::TaskPause_Response success(::rbpodo_msgs::srv::TaskPause_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::TaskPause_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::TaskPause_Response>()
{
  return rbpodo_msgs::srv::builder::Init_TaskPause_Response_success();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__SRV__DETAIL__TASK_PAUSE__BUILDER_HPP_
