// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rbpodo_msgs:msg/MoveJb2Point.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__STRUCT_HPP_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__msg__MoveJb2Point __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__msg__MoveJb2Point __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MoveJb2Point_
{
  using Type = MoveJb2Point_<ContainerAllocator>;

  explicit MoveJb2Point_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->joint.begin(), this->joint.end(), 0.0f);
      this->speed = 0.0f;
      this->acceleration = 0.0f;
      this->blending_value = 0.0f;
    }
  }

  explicit MoveJb2Point_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->joint.begin(), this->joint.end(), 0.0f);
      this->speed = 0.0f;
      this->acceleration = 0.0f;
      this->blending_value = 0.0f;
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
  using _blending_value_type =
    float;
  _blending_value_type blending_value;

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
  Type & set__blending_value(
    const float & _arg)
  {
    this->blending_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__msg__MoveJb2Point
    std::shared_ptr<rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__msg__MoveJb2Point
    std::shared_ptr<rbpodo_msgs::msg::MoveJb2Point_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJb2Point_ & other) const
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
    if (this->blending_value != other.blending_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJb2Point_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJb2Point_

// alias to use template instance with default allocator
using MoveJb2Point =
  rbpodo_msgs::msg::MoveJb2Point_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_JB2_POINT__STRUCT_HPP_
