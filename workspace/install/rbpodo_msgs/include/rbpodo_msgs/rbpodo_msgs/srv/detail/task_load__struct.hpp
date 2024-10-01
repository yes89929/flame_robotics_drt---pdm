// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rbpodo_msgs:srv/TaskLoad.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__STRUCT_HPP_
#define RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__srv__TaskLoad_Request __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__srv__TaskLoad_Request __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskLoad_Request_
{
  using Type = TaskLoad_Request_<ContainerAllocator>;

  explicit TaskLoad_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->program_name = "";
      this->timeout = 0.0f;
    }
  }

  explicit TaskLoad_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : program_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->program_name = "";
      this->timeout = 0.0f;
    }
  }

  // field types and members
  using _program_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _program_name_type program_name;
  using _timeout_type =
    float;
  _timeout_type timeout;

  // setters for named parameter idiom
  Type & set__program_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->program_name = _arg;
    return *this;
  }
  Type & set__timeout(
    const float & _arg)
  {
    this->timeout = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__srv__TaskLoad_Request
    std::shared_ptr<rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__srv__TaskLoad_Request
    std::shared_ptr<rbpodo_msgs::srv::TaskLoad_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskLoad_Request_ & other) const
  {
    if (this->program_name != other.program_name) {
      return false;
    }
    if (this->timeout != other.timeout) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskLoad_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskLoad_Request_

// alias to use template instance with default allocator
using TaskLoad_Request =
  rbpodo_msgs::srv::TaskLoad_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rbpodo_msgs


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__srv__TaskLoad_Response __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__srv__TaskLoad_Response __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct TaskLoad_Response_
{
  using Type = TaskLoad_Response_<ContainerAllocator>;

  explicit TaskLoad_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit TaskLoad_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__srv__TaskLoad_Response
    std::shared_ptr<rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__srv__TaskLoad_Response
    std::shared_ptr<rbpodo_msgs::srv::TaskLoad_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskLoad_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskLoad_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskLoad_Response_

// alias to use template instance with default allocator
using TaskLoad_Response =
  rbpodo_msgs::srv::TaskLoad_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rbpodo_msgs

namespace rbpodo_msgs
{

namespace srv
{

struct TaskLoad
{
  using Request = rbpodo_msgs::srv::TaskLoad_Request;
  using Response = rbpodo_msgs::srv::TaskLoad_Response;
};

}  // namespace srv

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__SRV__DETAIL__TASK_LOAD__STRUCT_HPP_
