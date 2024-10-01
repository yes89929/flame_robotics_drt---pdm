// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:srv/SetCartesianPoseControllerConfig.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__SET_CARTESIAN_POSE_CONTROLLER_CONFIG__BUILDER_HPP_
#define RBPODO_MSGS__SRV__DETAIL__SET_CARTESIAN_POSE_CONTROLLER_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/srv/detail/set_cartesian_pose_controller_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCartesianPoseControllerConfig_Request_alpha
{
public:
  explicit Init_SetCartesianPoseControllerConfig_Request_alpha(::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request alpha(::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request::_alpha_type arg)
  {
    msg_.alpha = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request msg_;
};

class Init_SetCartesianPoseControllerConfig_Request_gain
{
public:
  explicit Init_SetCartesianPoseControllerConfig_Request_gain(::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request & msg)
  : msg_(msg)
  {}
  Init_SetCartesianPoseControllerConfig_Request_alpha gain(::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request::_gain_type arg)
  {
    msg_.gain = std::move(arg);
    return Init_SetCartesianPoseControllerConfig_Request_alpha(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request msg_;
};

class Init_SetCartesianPoseControllerConfig_Request_t2
{
public:
  explicit Init_SetCartesianPoseControllerConfig_Request_t2(::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request & msg)
  : msg_(msg)
  {}
  Init_SetCartesianPoseControllerConfig_Request_gain t2(::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request::_t2_type arg)
  {
    msg_.t2 = std::move(arg);
    return Init_SetCartesianPoseControllerConfig_Request_gain(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request msg_;
};

class Init_SetCartesianPoseControllerConfig_Request_t1
{
public:
  Init_SetCartesianPoseControllerConfig_Request_t1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetCartesianPoseControllerConfig_Request_t2 t1(::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request::_t1_type arg)
  {
    msg_.t1 = std::move(arg);
    return Init_SetCartesianPoseControllerConfig_Request_t2(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Request>()
{
  return rbpodo_msgs::srv::builder::Init_SetCartesianPoseControllerConfig_Request_t1();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace srv
{

namespace builder
{

class Init_SetCartesianPoseControllerConfig_Response_success
{
public:
  Init_SetCartesianPoseControllerConfig_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response success(::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::srv::SetCartesianPoseControllerConfig_Response>()
{
  return rbpodo_msgs::srv::builder::Init_SetCartesianPoseControllerConfig_Response_success();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__SRV__DETAIL__SET_CARTESIAN_POSE_CONTROLLER_CONFIG__BUILDER_HPP_
