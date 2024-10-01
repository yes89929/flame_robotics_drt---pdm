// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rbpodo_msgs:srv/SetCartesianVelocityControllerConfig.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__SET_CARTESIAN_VELOCITY_CONTROLLER_CONFIG__STRUCT_HPP_
#define RBPODO_MSGS__SRV__DETAIL__SET_CARTESIAN_VELOCITY_CONTROLLER_CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__srv__SetCartesianVelocityControllerConfig_Request __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__srv__SetCartesianVelocityControllerConfig_Request __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetCartesianVelocityControllerConfig_Request_
{
  using Type = SetCartesianVelocityControllerConfig_Request_<ContainerAllocator>;

  explicit SetCartesianVelocityControllerConfig_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->t1 = 0.0;
      this->t2 = 0.0;
      this->gain = 0.0;
      this->alpha = 0.0;
    }
  }

  explicit SetCartesianVelocityControllerConfig_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->t1 = 0.0;
      this->t2 = 0.0;
      this->gain = 0.0;
      this->alpha = 0.0;
    }
  }

  // field types and members
  using _t1_type =
    double;
  _t1_type t1;
  using _t2_type =
    double;
  _t2_type t2;
  using _gain_type =
    double;
  _gain_type gain;
  using _alpha_type =
    double;
  _alpha_type alpha;

  // setters for named parameter idiom
  Type & set__t1(
    const double & _arg)
  {
    this->t1 = _arg;
    return *this;
  }
  Type & set__t2(
    const double & _arg)
  {
    this->t2 = _arg;
    return *this;
  }
  Type & set__gain(
    const double & _arg)
  {
    this->gain = _arg;
    return *this;
  }
  Type & set__alpha(
    const double & _arg)
  {
    this->alpha = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__srv__SetCartesianVelocityControllerConfig_Request
    std::shared_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__srv__SetCartesianVelocityControllerConfig_Request
    std::shared_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetCartesianVelocityControllerConfig_Request_ & other) const
  {
    if (this->t1 != other.t1) {
      return false;
    }
    if (this->t2 != other.t2) {
      return false;
    }
    if (this->gain != other.gain) {
      return false;
    }
    if (this->alpha != other.alpha) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetCartesianVelocityControllerConfig_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetCartesianVelocityControllerConfig_Request_

// alias to use template instance with default allocator
using SetCartesianVelocityControllerConfig_Request =
  rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rbpodo_msgs


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__srv__SetCartesianVelocityControllerConfig_Response __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__srv__SetCartesianVelocityControllerConfig_Response __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetCartesianVelocityControllerConfig_Response_
{
  using Type = SetCartesianVelocityControllerConfig_Response_<ContainerAllocator>;

  explicit SetCartesianVelocityControllerConfig_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit SetCartesianVelocityControllerConfig_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__srv__SetCartesianVelocityControllerConfig_Response
    std::shared_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__srv__SetCartesianVelocityControllerConfig_Response
    std::shared_ptr<rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetCartesianVelocityControllerConfig_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetCartesianVelocityControllerConfig_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetCartesianVelocityControllerConfig_Response_

// alias to use template instance with default allocator
using SetCartesianVelocityControllerConfig_Response =
  rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rbpodo_msgs

namespace rbpodo_msgs
{

namespace srv
{

struct SetCartesianVelocityControllerConfig
{
  using Request = rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Request;
  using Response = rbpodo_msgs::srv::SetCartesianVelocityControllerConfig_Response;
};

}  // namespace srv

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__SRV__DETAIL__SET_CARTESIAN_VELOCITY_CONTROLLER_CONFIG__STRUCT_HPP_
