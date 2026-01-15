// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from center_msg_pkg:msg/Singlecenter.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__STRUCT_HPP_
#define CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__center_msg_pkg__msg__Singlecenter __attribute__((deprecated))
#else
# define DEPRECATED__center_msg_pkg__msg__Singlecenter __declspec(deprecated)
#endif

namespace center_msg_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Singlecenter_
{
  using Type = Singlecenter_<ContainerAllocator>;

  explicit Singlecenter_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->center_x = 0.0f;
      this->center_y = 0.0f;
    }
  }

  explicit Singlecenter_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->center_x = 0.0f;
      this->center_y = 0.0f;
    }
  }

  // field types and members
  using _center_x_type =
    float;
  _center_x_type center_x;
  using _center_y_type =
    float;
  _center_y_type center_y;

  // setters for named parameter idiom
  Type & set__center_x(
    const float & _arg)
  {
    this->center_x = _arg;
    return *this;
  }
  Type & set__center_y(
    const float & _arg)
  {
    this->center_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    center_msg_pkg::msg::Singlecenter_<ContainerAllocator> *;
  using ConstRawPtr =
    const center_msg_pkg::msg::Singlecenter_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<center_msg_pkg::msg::Singlecenter_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<center_msg_pkg::msg::Singlecenter_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      center_msg_pkg::msg::Singlecenter_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<center_msg_pkg::msg::Singlecenter_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      center_msg_pkg::msg::Singlecenter_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<center_msg_pkg::msg::Singlecenter_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<center_msg_pkg::msg::Singlecenter_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<center_msg_pkg::msg::Singlecenter_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__center_msg_pkg__msg__Singlecenter
    std::shared_ptr<center_msg_pkg::msg::Singlecenter_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__center_msg_pkg__msg__Singlecenter
    std::shared_ptr<center_msg_pkg::msg::Singlecenter_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Singlecenter_ & other) const
  {
    if (this->center_x != other.center_x) {
      return false;
    }
    if (this->center_y != other.center_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Singlecenter_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Singlecenter_

// alias to use template instance with default allocator
using Singlecenter =
  center_msg_pkg::msg::Singlecenter_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace center_msg_pkg

#endif  // CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__STRUCT_HPP_
