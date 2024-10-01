// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:action/MoveJ.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__ACTION__DETAIL__MOVE_J__BUILDER_HPP_
#define RBPODO_MSGS__ACTION__DETAIL__MOVE_J__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/action/detail/move_j__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace action
{

namespace builder
{

class Init_MoveJ_Goal_time_for_waiting_start
{
public:
  explicit Init_MoveJ_Goal_time_for_waiting_start(::rbpodo_msgs::action::MoveJ_Goal & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::action::MoveJ_Goal time_for_waiting_start(::rbpodo_msgs::action::MoveJ_Goal::_time_for_waiting_start_type arg)
  {
    msg_.time_for_waiting_start = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_Goal msg_;
};

class Init_MoveJ_Goal_acceleration
{
public:
  explicit Init_MoveJ_Goal_acceleration(::rbpodo_msgs::action::MoveJ_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveJ_Goal_time_for_waiting_start acceleration(::rbpodo_msgs::action::MoveJ_Goal::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_MoveJ_Goal_time_for_waiting_start(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_Goal msg_;
};

class Init_MoveJ_Goal_speed
{
public:
  explicit Init_MoveJ_Goal_speed(::rbpodo_msgs::action::MoveJ_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveJ_Goal_acceleration speed(::rbpodo_msgs::action::MoveJ_Goal::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_MoveJ_Goal_acceleration(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_Goal msg_;
};

class Init_MoveJ_Goal_joint
{
public:
  Init_MoveJ_Goal_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJ_Goal_speed joint(::rbpodo_msgs::action::MoveJ_Goal::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_MoveJ_Goal_speed(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::action::MoveJ_Goal>()
{
  return rbpodo_msgs::action::builder::Init_MoveJ_Goal_joint();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace action
{

namespace builder
{

class Init_MoveJ_Result_success
{
public:
  Init_MoveJ_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::action::MoveJ_Result success(::rbpodo_msgs::action::MoveJ_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::action::MoveJ_Result>()
{
  return rbpodo_msgs::action::builder::Init_MoveJ_Result_success();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace action
{

namespace builder
{

class Init_MoveJ_Feedback_state
{
public:
  Init_MoveJ_Feedback_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::action::MoveJ_Feedback state(::rbpodo_msgs::action::MoveJ_Feedback::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::action::MoveJ_Feedback>()
{
  return rbpodo_msgs::action::builder::Init_MoveJ_Feedback_state();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace action
{

namespace builder
{

class Init_MoveJ_SendGoal_Request_goal
{
public:
  explicit Init_MoveJ_SendGoal_Request_goal(::rbpodo_msgs::action::MoveJ_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::action::MoveJ_SendGoal_Request goal(::rbpodo_msgs::action::MoveJ_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_SendGoal_Request msg_;
};

class Init_MoveJ_SendGoal_Request_goal_id
{
public:
  Init_MoveJ_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJ_SendGoal_Request_goal goal_id(::rbpodo_msgs::action::MoveJ_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveJ_SendGoal_Request_goal(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::action::MoveJ_SendGoal_Request>()
{
  return rbpodo_msgs::action::builder::Init_MoveJ_SendGoal_Request_goal_id();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace action
{

namespace builder
{

class Init_MoveJ_SendGoal_Response_stamp
{
public:
  explicit Init_MoveJ_SendGoal_Response_stamp(::rbpodo_msgs::action::MoveJ_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::action::MoveJ_SendGoal_Response stamp(::rbpodo_msgs::action::MoveJ_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_SendGoal_Response msg_;
};

class Init_MoveJ_SendGoal_Response_accepted
{
public:
  Init_MoveJ_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJ_SendGoal_Response_stamp accepted(::rbpodo_msgs::action::MoveJ_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveJ_SendGoal_Response_stamp(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::action::MoveJ_SendGoal_Response>()
{
  return rbpodo_msgs::action::builder::Init_MoveJ_SendGoal_Response_accepted();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace action
{

namespace builder
{

class Init_MoveJ_GetResult_Request_goal_id
{
public:
  Init_MoveJ_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rbpodo_msgs::action::MoveJ_GetResult_Request goal_id(::rbpodo_msgs::action::MoveJ_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::action::MoveJ_GetResult_Request>()
{
  return rbpodo_msgs::action::builder::Init_MoveJ_GetResult_Request_goal_id();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace action
{

namespace builder
{

class Init_MoveJ_GetResult_Response_result
{
public:
  explicit Init_MoveJ_GetResult_Response_result(::rbpodo_msgs::action::MoveJ_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::action::MoveJ_GetResult_Response result(::rbpodo_msgs::action::MoveJ_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_GetResult_Response msg_;
};

class Init_MoveJ_GetResult_Response_status
{
public:
  Init_MoveJ_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJ_GetResult_Response_result status(::rbpodo_msgs::action::MoveJ_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveJ_GetResult_Response_result(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::action::MoveJ_GetResult_Response>()
{
  return rbpodo_msgs::action::builder::Init_MoveJ_GetResult_Response_status();
}

}  // namespace rbpodo_msgs


namespace rbpodo_msgs
{

namespace action
{

namespace builder
{

class Init_MoveJ_FeedbackMessage_feedback
{
public:
  explicit Init_MoveJ_FeedbackMessage_feedback(::rbpodo_msgs::action::MoveJ_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::action::MoveJ_FeedbackMessage feedback(::rbpodo_msgs::action::MoveJ_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_FeedbackMessage msg_;
};

class Init_MoveJ_FeedbackMessage_goal_id
{
public:
  Init_MoveJ_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJ_FeedbackMessage_feedback goal_id(::rbpodo_msgs::action::MoveJ_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveJ_FeedbackMessage_feedback(msg_);
  }

private:
  ::rbpodo_msgs::action::MoveJ_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::action::MoveJ_FeedbackMessage>()
{
  return rbpodo_msgs::action::builder::Init_MoveJ_FeedbackMessage_goal_id();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__ACTION__DETAIL__MOVE_J__BUILDER_HPP_
