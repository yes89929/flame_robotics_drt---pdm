// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:msg/MovePbPoint.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__BUILDER_HPP_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/msg/detail/move_pb_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace msg
{

namespace builder
{

class Init_MovePbPoint_blending_value
{
public:
  explicit Init_MovePbPoint_blending_value(::rbpodo_msgs::msg::MovePbPoint & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::msg::MovePbPoint blending_value(::rbpodo_msgs::msg::MovePbPoint::_blending_value_type arg)
  {
    msg_.blending_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::msg::MovePbPoint msg_;
};

class Init_MovePbPoint_blending_option
{
public:
  explicit Init_MovePbPoint_blending_option(::rbpodo_msgs::msg::MovePbPoint & msg)
  : msg_(msg)
  {}
  Init_MovePbPoint_blending_value blending_option(::rbpodo_msgs::msg::MovePbPoint::_blending_option_type arg)
  {
    msg_.blending_option = std::move(arg);
    return Init_MovePbPoint_blending_value(msg_);
  }

private:
  ::rbpodo_msgs::msg::MovePbPoint msg_;
};

class Init_MovePbPoint_speed
{
public:
  explicit Init_MovePbPoint_speed(::rbpodo_msgs::msg::MovePbPoint & msg)
  : msg_(msg)
  {}
  Init_MovePbPoint_blending_option speed(::rbpodo_msgs::msg::MovePbPoint::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_MovePbPoint_blending_option(msg_);
  }

private:
  ::rbpodo_msgs::msg::MovePbPoint msg_;
};

class Init_MovePbPoint_point
{
public:
  Init_MovePbPoint_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MovePbPoint_speed point(::rbpodo_msgs::msg::MovePbPoint::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_MovePbPoint_speed(msg_);
  }

private:
  ::rbpodo_msgs::msg::MovePbPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::msg::MovePbPoint>()
{
  return rbpodo_msgs::msg::builder::Init_MovePbPoint_point();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__BUILDER_HPP_
