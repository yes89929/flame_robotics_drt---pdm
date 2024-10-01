// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:srv/TaskResume.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__TASK_RESUME__BUILDER_HPP_
#define RBPODO_MSGS__SRV__DETAIL__TASK_RESUME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/srv/detail/task_resume__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskResume_Request_collision
{
public:
  Init_TaskResume_Request_collision()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::TaskResume_Request collision(::rbpodo_msgs::srv::TaskResume_Request::_collision_type arg)
  {
    msg_.collision = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::TaskResume_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::TaskResume_Request>()
{
  return rbpodo_msgs::srv::builder::Init_TaskResume_Request_collision();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_TaskResume_Response_success
{
public:
  Init_TaskResume_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::TaskResume_Response success(::rbpodo_msgs::srv::TaskResume_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::TaskResume_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::TaskResume_Response>()
{
  return rbpodo_msgs::srv::builder::Init_TaskResume_Response_success();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__SRV__DETAIL__TASK_RESUME__BUILDER_HPP_
