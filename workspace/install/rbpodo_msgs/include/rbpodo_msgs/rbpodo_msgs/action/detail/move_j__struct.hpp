// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rbpodo_msgs:action/MoveJ.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__ACTION__DETAIL__MOVE_J__STRUCT_HPP_
#define RBPODO_MSGS__ACTION__DETAIL__MOVE_J__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__action__MoveJ_Goal __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__action__MoveJ_Goal __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveJ_Goal_
{
  using Type = MoveJ_Goal_<ContainerAllocator>;

  explicit MoveJ_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->joint.begin(), this->joint.end(), 0.0f);
      this->speed = 0.0f;
      this->acceleration = 0.0f;
      this->time_for_waiting_start = 0.0f;
    }
  }

  explicit MoveJ_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->joint.begin(), this->joint.end(), 0.0f);
      this->speed = 0.0f;
      this->acceleration = 0.0f;
      this->time_for_waiting_start = 0.0f;
    }
  }

  // field types and members
  using _joint_type =
    std::array<float, 6>;
  _joint_type joint;
  using _speed_type =
    float;
  _speed_type speed;
  using _acceleration_type =
    float;
  _acceleration_type acceleration;
  using _time_for_waiting_start_type =
    float;
  _time_for_waiting_start_type time_for_waiting_start;

  // setters for named parameter idiom
  Type & set__joint(
    const std::array<float, 6> & _arg)
  {
    this->joint = _arg;
    return *this;
  }
  Type & set__speed(
    const float & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__acceleration(
    const float & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__time_for_waiting_start(
    const float & _arg)
  {
    this->time_for_waiting_start = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_Goal
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_Goal
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_Goal_ & other) const
  {
    if (this->joint != other.joint) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->time_for_waiting_start != other.time_for_waiting_start) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_Goal_

// alias to use template instance with default allocator
using MoveJ_Goal =
  rbpodo_msgs::action::MoveJ_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace rbpodo_msgs


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__action__MoveJ_Result __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__action__MoveJ_Result __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveJ_Result_
{
  using Type = MoveJ_Result_<ContainerAllocator>;

  explicit MoveJ_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MoveJ_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_Result
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_Result
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_Result_

// alias to use template instance with default allocator
using MoveJ_Result =
  rbpodo_msgs::action::MoveJ_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace rbpodo_msgs


// Include directives for member types
// Member 'state'
#include "rbpodo_msgs/msg/detail/system_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__action__MoveJ_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__action__MoveJ_Feedback __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveJ_Feedback_
{
  using Type = MoveJ_Feedback_<ContainerAllocator>;

  explicit MoveJ_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_init)
  {
    (void)_init;
  }

  explicit MoveJ_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _state_type =
    rbpodo_msgs::msg::SystemState_<ContainerAllocator>;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const rbpodo_msgs::msg::SystemState_<ContainerAllocator> & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_Feedback
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_Feedback
    std::shared_ptr<rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_Feedback_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_Feedback_

// alias to use template instance with default allocator
using MoveJ_Feedback =
  rbpodo_msgs::action::MoveJ_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace rbpodo_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "rbpodo_msgs/action/detail/move_j__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__action__MoveJ_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__action__MoveJ_SendGoal_Request __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveJ_SendGoal_Request_
{
  using Type = MoveJ_SendGoal_Request_<ContainerAllocator>;

  explicit MoveJ_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit MoveJ_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const rbpodo_msgs::action::MoveJ_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_SendGoal_Request
    std::shared_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_SendGoal_Request
    std::shared_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_SendGoal_Request_

// alias to use template instance with default allocator
using MoveJ_SendGoal_Request =
  rbpodo_msgs::action::MoveJ_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace rbpodo_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__action__MoveJ_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__action__MoveJ_SendGoal_Response __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveJ_SendGoal_Response_
{
  using Type = MoveJ_SendGoal_Response_<ContainerAllocator>;

  explicit MoveJ_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit MoveJ_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_SendGoal_Response
    std::shared_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_SendGoal_Response
    std::shared_ptr<rbpodo_msgs::action::MoveJ_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_SendGoal_Response_

// alias to use template instance with default allocator
using MoveJ_SendGoal_Response =
  rbpodo_msgs::action::MoveJ_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace rbpodo_msgs

namespace rbpodo_msgs
{

namespace action
{

struct MoveJ_SendGoal
{
  using Request = rbpodo_msgs::action::MoveJ_SendGoal_Request;
  using Response = rbpodo_msgs::action::MoveJ_SendGoal_Response;
};

}  // namespace action

}  // namespace rbpodo_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__action__MoveJ_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__action__MoveJ_GetResult_Request __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveJ_GetResult_Request_
{
  using Type = MoveJ_GetResult_Request_<ContainerAllocator>;

  explicit MoveJ_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit MoveJ_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_GetResult_Request
    std::shared_ptr<rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_GetResult_Request
    std::shared_ptr<rbpodo_msgs::action::MoveJ_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_GetResult_Request_

// alias to use template instance with default allocator
using MoveJ_GetResult_Request =
  rbpodo_msgs::action::MoveJ_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace rbpodo_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "rbpodo_msgs/action/detail/move_j__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__action__MoveJ_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__action__MoveJ_GetResult_Response __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveJ_GetResult_Response_
{
  using Type = MoveJ_GetResult_Response_<ContainerAllocator>;

  explicit MoveJ_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit MoveJ_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const rbpodo_msgs::action::MoveJ_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_GetResult_Response
    std::shared_ptr<rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_GetResult_Response
    std::shared_ptr<rbpodo_msgs::action::MoveJ_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_GetResult_Response_

// alias to use template instance with default allocator
using MoveJ_GetResult_Response =
  rbpodo_msgs::action::MoveJ_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace rbpodo_msgs

namespace rbpodo_msgs
{

namespace action
{

struct MoveJ_GetResult
{
  using Request = rbpodo_msgs::action::MoveJ_GetResult_Request;
  using Response = rbpodo_msgs::action::MoveJ_GetResult_Response;
};

}  // namespace action

}  // namespace rbpodo_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "rbpodo_msgs/action/detail/move_j__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__action__MoveJ_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__action__MoveJ_FeedbackMessage __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct MoveJ_FeedbackMessage_
{
  using Type = MoveJ_FeedbackMessage_<ContainerAllocator>;

  explicit MoveJ_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit MoveJ_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const rbpodo_msgs::action::MoveJ_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_FeedbackMessage
    std::shared_ptr<rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__action__MoveJ_FeedbackMessage
    std::shared_ptr<rbpodo_msgs::action::MoveJ_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ_FeedbackMessage_

// alias to use template instance with default allocator
using MoveJ_FeedbackMessage =
  rbpodo_msgs::action::MoveJ_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace rbpodo_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace rbpodo_msgs
{

namespace action
{

struct MoveJ
{
  /// The goal message defined in the action definition.
  using Goal = rbpodo_msgs::action::MoveJ_Goal;
  /// The result message defined in the action definition.
  using Result = rbpodo_msgs::action::MoveJ_Result;
  /// The feedback message defined in the action definition.
  using Feedback = rbpodo_msgs::action::MoveJ_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = rbpodo_msgs::action::MoveJ_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = rbpodo_msgs::action::MoveJ_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = rbpodo_msgs::action::MoveJ_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct MoveJ MoveJ;

}  // namespace action

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__ACTION__DETAIL__MOVE_J__STRUCT_HPP_
