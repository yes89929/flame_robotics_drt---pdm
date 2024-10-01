// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:srv/SetSpeedBar.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__SET_SPEED_BAR__BUILDER_HPP_
#define RBPODO_MSGS__SRV__DETAIL__SET_SPEED_BAR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/srv/detail/set_speed_bar__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSpeedBar_Request_speed
{
public:
  Init_SetSpeedBar_Request_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::SetSpeedBar_Request speed(::rbpodo_msgs::srv::SetSpeedBar_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetSpeedBar_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::SetSpeedBar_Request>()
{
  return rbpodo_msgs::srv::builder::Init_SetSpeedBar_Request_speed();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_SetSpeedBar_Response_success
{
public:
  Init_SetSpeedBar_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::SetSpeedBar_Response success(::rbpodo_msgs::srv::SetSpeedBar_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetSpeedBar_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::SetSpeedBar_Response>()
{
  return rbpodo_msgs::srv::builder::Init_SetSpeedBar_Response_success();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__SRV__DETAIL__SET_SPEED_BAR__BUILDER_HPP_
