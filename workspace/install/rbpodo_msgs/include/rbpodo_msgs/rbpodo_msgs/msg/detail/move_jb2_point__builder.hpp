// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:msg/MoveJb2Point.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__BUILDER_HPP_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/msg/detail/move_jb2_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace msg
{

namespace builder
{

class Init_MoveJb2Point_blending_value
{
public:
  explicit Init_MoveJb2Point_blending_value(::rbpodo_msgs::msg::MoveJb2Point & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::msg::MoveJb2Point blending_value(::rbpodo_msgs::msg::MoveJb2Point::_blending_value_type arg)
  {
    msg_.blending_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::msg::MoveJb2Point msg_;
};

class Init_MoveJb2Point_acceleration
{
public:
  explicit Init_MoveJb2Point_acceleration(::rbpodo_msgs::msg::MoveJb2Point & msg)
  : msg_(msg)
  {}
  Init_MoveJb2Point_blending_value acceleration(::rbpodo_msgs::msg::MoveJb2Point::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_MoveJb2Point_blending_value(msg_);
  }

private:
  ::rbpodo_msgs::msg::MoveJb2Point msg_;
};

class Init_MoveJb2Point_speed
{
public:
  explicit Init_MoveJb2Point_speed(::rbpodo_msgs::msg::MoveJb2Point & msg)
  : msg_(msg)
  {}
  Init_MoveJb2Point_acceleration speed(::rbpodo_msgs::msg::MoveJb2Point::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_MoveJb2Point_acceleration(msg_);
  }

private:
  ::rbpodo_msgs::msg::MoveJb2Point msg_;
};

class Init_MoveJb2Point_joint
{
public:
  Init_MoveJb2Point_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJb2Point_speed joint(::rbpodo_msgs::msg::MoveJb2Point::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_MoveJb2Point_speed(msg_);
  }

private:
  ::rbpodo_msgs::msg::MoveJb2Point msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::msg::MoveJb2Point>()
{
  return rbpodo_msgs::msg::builder::Init_MoveJb2Point_joint();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__BUILDER_HPP_
