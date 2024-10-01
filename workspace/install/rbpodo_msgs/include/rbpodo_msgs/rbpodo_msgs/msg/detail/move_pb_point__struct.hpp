// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rbpodo_msgs:msg/MovePbPoint.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__STRUCT_HPP_
#define RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__msg__MovePbPoint __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__msg__MovePbPoint __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MovePbPoint_
{
  using Type = MovePbPoint_<ContainerAllocator>;

  explicit MovePbPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->point.begin(), this->point.end(), 0.0f);
      this->speed = 0.0f;
      this->blending_option = 0;
      this->blending_value = 0.0f;
    }
  }

  explicit MovePbPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 6>::iterator, float>(this->point.begin(), this->point.end(), 0.0f);
      this->speed = 0.0f;
      this->blending_option = 0;
      this->blending_value = 0.0f;
    }
  }

  // field types and members
  using _point_type =
    std::array<float, 6>;
  _point_type point;
  using _speed_type =
    float;
  _speed_type speed;
  using _blending_option_type =
    uint8_t;
  _blending_option_type blending_option;
  using _blending_value_type =
    float;
  _blending_value_type blending_value;

  // setters for named parameter idiom
  Type & set__point(
    const std::array<float, 6> & _arg)
  {
    this->point = _arg;
    return *this;
  }
  Type & set__speed(
    const float & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__blending_option(
    const uint8_t & _arg)
  {
    this->blending_option = _arg;
    return *this;
  }
  Type & set__blending_value(
    const float & _arg)
  {
    this->blending_value = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t BLENDING_OPTION_RATIO =
    0u;
  static constexpr uint8_t BLENDING_OPTION_DISTANCE =
    1u;

  // pointer types
  using RawPtr =
    rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__msg__MovePbPoint
    std::shared_ptr<rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__msg__MovePbPoint
    std::shared_ptr<rbpodo_msgs::msg::MovePbPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MovePbPoint_ & other) const
  {
    if (this->point != other.point) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->blending_option != other.blending_option) {
      return false;
    }
    if (this->blending_value != other.blending_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const MovePbPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MovePbPoint_

// alias to use template instance with default allocator
using MovePbPoint =
  rbpodo_msgs::msg::MovePbPoint_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MovePbPoint_<ContainerAllocator>::BLENDING_OPTION_RATIO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MovePbPoint_<ContainerAllocator>::BLENDING_OPTION_DISTANCE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__MSG__DETAIL__MOVE_PB_POINT__STRUCT_HPP_
