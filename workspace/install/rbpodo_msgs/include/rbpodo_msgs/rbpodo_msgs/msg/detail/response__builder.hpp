// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:msg/Response.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__RESPONSE__BUILDER_HPP_
#define RBPODO_MSGS__MSG__DETAIL__RESPONSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/msg/detail/response__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace msg
{

namespace builder
{

class Init_Response_error
{
public:
  explicit Init_Response_error(::rbpodo_msgs::msg::Response & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::msg::Response error(::rbpodo_msgs::msg::Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::msg::Response msg_;
};

class Init_Response_msg
{
public:
  explicit Init_Response_msg(::rbpodo_msgs::msg::Response & msg)
  : msg_(msg)
  {}
  Init_Response_error msg(::rbpodo_msgs::msg::Response::_msg_type arg)
  {
    msg_.msg = std::move(arg);
    return Init_Response_error(msg_);
  }

private:
  ::rbpodo_msgs::msg::Response msg_;
};

class Init_Response_category
{
public:
  explicit Init_Response_category(::rbpodo_msgs::msg::Response & msg)
  : msg_(msg)
  {}
  Init_Response_msg category(::rbpodo_msgs::msg::Response::_category_type arg)
  {
    msg_.category = std::move(arg);
    return Init_Response_msg(msg_);
  }

private:
  ::rbpodo_msgs::msg::Response msg_;
};

class Init_Response_type
{
public:
  Init_Response_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Response_category type(::rbpodo_msgs::msg::Response::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Response_category(msg_);
  }

private:
  ::rbpodo_msgs::msg::Response msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::msg::Response>()
{
  return rbpodo_msgs::msg::builder::Init_Response_type();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__MSG__DETAIL__RESPONSE__BUILDER_HPP_
