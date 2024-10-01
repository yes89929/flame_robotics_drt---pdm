// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rbpodo_msgs:action/MoveL.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__ACTION__DETAIL__MOVE_L__TRAITS_HPP_
#define RBPODO_MSGS__ACTION__DETAIL__MOVE_L__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rbpodo_msgs/action/detail/move_l__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rbpodo_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveL_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: point
  {
    if (msg.point.size() == 0) {
      out << "point: []";
    } else {
      out << "point: [";
      size_t pending_items = msg.point.size();
      for (auto item : msg.point) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: acceleration
  {
    out << "acceleration: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration, out);
    out << ", ";
  }

  // member: time_for_waiting_start
  {
    out << "time_for_waiting_start: ";
    rosidl_generator_traits::value_to_yaml(msg.time_for_waiting_start, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveL_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.point.size() == 0) {
      out << "point: []\n";
    } else {
      out << "point:\n";
      for (auto item : msg.point) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration, out);
    out << "\n";
  }

  // member: time_for_waiting_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_for_waiting_start: ";
    rosidl_generator_traits::value_to_yaml(msg.time_for_waiting_start, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveL_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::action::MoveL_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::action::MoveL_Goal & msg)
{
  return rbpodo_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_Goal>()
{
  return "rbpodo_msgs::action::MoveL_Goal";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_Goal>()
{
  return "rbpodo_msgs/action/MoveL_Goal";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::action::MoveL_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rbpodo_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveL_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveL_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveL_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::action::MoveL_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::action::MoveL_Result & msg)
{
  return rbpodo_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_Result>()
{
  return "rbpodo_msgs::action::MoveL_Result";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_Result>()
{
  return "rbpodo_msgs/action/MoveL_Result";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::action::MoveL_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'state'
#include "rbpodo_msgs/msg/detail/system_state__traits.hpp"

namespace rbpodo_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveL_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    to_flow_style_yaml(msg.state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveL_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state:\n";
    to_block_style_yaml(msg.state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveL_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::action::MoveL_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::action::MoveL_Feedback & msg)
{
  return rbpodo_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_Feedback>()
{
  return "rbpodo_msgs::action::MoveL_Feedback";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_Feedback>()
{
  return "rbpodo_msgs/action/MoveL_Feedback";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_Feedback>
  : std::integral_constant<bool, has_fixed_size<rbpodo_msgs::msg::SystemState>::value> {};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_Feedback>
  : std::integral_constant<bool, has_bounded_size<rbpodo_msgs::msg::SystemState>::value> {};

template<>
struct is_message<rbpodo_msgs::action::MoveL_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "rbpodo_msgs/action/detail/move_l__traits.hpp"

namespace rbpodo_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveL_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveL_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveL_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::action::MoveL_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::action::MoveL_SendGoal_Request & msg)
{
  return rbpodo_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_SendGoal_Request>()
{
  return "rbpodo_msgs::action::MoveL_SendGoal_Request";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_SendGoal_Request>()
{
  return "rbpodo_msgs/action/MoveL_SendGoal_Request";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<rbpodo_msgs::action::MoveL_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<rbpodo_msgs::action::MoveL_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<rbpodo_msgs::action::MoveL_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rbpodo_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveL_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveL_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveL_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::action::MoveL_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::action::MoveL_SendGoal_Response & msg)
{
  return rbpodo_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_SendGoal_Response>()
{
  return "rbpodo_msgs::action::MoveL_SendGoal_Response";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_SendGoal_Response>()
{
  return "rbpodo_msgs/action/MoveL_SendGoal_Response";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<rbpodo_msgs::action::MoveL_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_SendGoal>()
{
  return "rbpodo_msgs::action::MoveL_SendGoal";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_SendGoal>()
{
  return "rbpodo_msgs/action/MoveL_SendGoal";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<rbpodo_msgs::action::MoveL_SendGoal_Request>::value &&
    has_fixed_size<rbpodo_msgs::action::MoveL_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<rbpodo_msgs::action::MoveL_SendGoal_Request>::value &&
    has_bounded_size<rbpodo_msgs::action::MoveL_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<rbpodo_msgs::action::MoveL_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<rbpodo_msgs::action::MoveL_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rbpodo_msgs::action::MoveL_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rbpodo_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveL_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveL_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveL_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::action::MoveL_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::action::MoveL_GetResult_Request & msg)
{
  return rbpodo_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_GetResult_Request>()
{
  return "rbpodo_msgs::action::MoveL_GetResult_Request";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_GetResult_Request>()
{
  return "rbpodo_msgs/action/MoveL_GetResult_Request";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<rbpodo_msgs::action::MoveL_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "rbpodo_msgs/action/detail/move_l__traits.hpp"

namespace rbpodo_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveL_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveL_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveL_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::action::MoveL_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::action::MoveL_GetResult_Response & msg)
{
  return rbpodo_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_GetResult_Response>()
{
  return "rbpodo_msgs::action::MoveL_GetResult_Response";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_GetResult_Response>()
{
  return "rbpodo_msgs/action/MoveL_GetResult_Response";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<rbpodo_msgs::action::MoveL_Result>::value> {};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<rbpodo_msgs::action::MoveL_Result>::value> {};

template<>
struct is_message<rbpodo_msgs::action::MoveL_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_GetResult>()
{
  return "rbpodo_msgs::action::MoveL_GetResult";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_GetResult>()
{
  return "rbpodo_msgs/action/MoveL_GetResult";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<rbpodo_msgs::action::MoveL_GetResult_Request>::value &&
    has_fixed_size<rbpodo_msgs::action::MoveL_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<rbpodo_msgs::action::MoveL_GetResult_Request>::value &&
    has_bounded_size<rbpodo_msgs::action::MoveL_GetResult_Response>::value
  >
{
};

template<>
struct is_service<rbpodo_msgs::action::MoveL_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<rbpodo_msgs::action::MoveL_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rbpodo_msgs::action::MoveL_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "rbpodo_msgs/action/detail/move_l__traits.hpp"

namespace rbpodo_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const MoveL_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveL_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveL_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::action::MoveL_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::action::MoveL_FeedbackMessage & msg)
{
  return rbpodo_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::action::MoveL_FeedbackMessage>()
{
  return "rbpodo_msgs::action::MoveL_FeedbackMessage";
}

template<>
inline const char * name<rbpodo_msgs::action::MoveL_FeedbackMessage>()
{
  return "rbpodo_msgs/action/MoveL_FeedbackMessage";
}

template<>
struct has_fixed_size<rbpodo_msgs::action::MoveL_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<rbpodo_msgs::action::MoveL_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<rbpodo_msgs::action::MoveL_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<rbpodo_msgs::action::MoveL_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<rbpodo_msgs::action::MoveL_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<rbpodo_msgs::action::MoveL>
  : std::true_type
{
};

template<>
struct is_action_goal<rbpodo_msgs::action::MoveL_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<rbpodo_msgs::action::MoveL_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<rbpodo_msgs::action::MoveL_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // RBPODO_MSGS__ACTION__DETAIL__MOVE_L__TRAITS_HPP_
