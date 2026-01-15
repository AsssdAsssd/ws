// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from center_msg_pkg:msg/Center.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__CENTER__STRUCT_HPP_
#define CENTER_MSG_PKG__MSG__DETAIL__CENTER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'boxes'
#include "center_msg_pkg/msg/detail/singlecenter__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__center_msg_pkg__msg__Center __attribute__((deprecated))
#else
# define DEPRECATED__center_msg_pkg__msg__Center __declspec(deprecated)
#endif

namespace center_msg_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Center_
{
  using Type = Center_<ContainerAllocator>;

  explicit Center_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->box_num = 0ul;
    }
  }

  explicit Center_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->box_num = 0ul;
    }
  }

  // field types and members
  using _boxes_type =
    std::vector<center_msg_pkg::msg::Singlecenter_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<center_msg_pkg::msg::Singlecenter_<ContainerAllocator>>>;
  _boxes_type boxes;
  using _box_num_type =
    uint32_t;
  _box_num_type box_num;

  // setters for named parameter idiom
  Type & set__boxes(
    const std::vector<center_msg_pkg::msg::Singlecenter_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<center_msg_pkg::msg::Singlecenter_<ContainerAllocator>>> & _arg)
  {
    this->boxes = _arg;
    return *this;
  }
  Type & set__box_num(
    const uint32_t & _arg)
  {
    this->box_num = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    center_msg_pkg::msg::Center_<ContainerAllocator> *;
  using ConstRawPtr =
    const center_msg_pkg::msg::Center_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<center_msg_pkg::msg::Center_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<center_msg_pkg::msg::Center_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      center_msg_pkg::msg::Center_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<center_msg_pkg::msg::Center_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      center_msg_pkg::msg::Center_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<center_msg_pkg::msg::Center_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<center_msg_pkg::msg::Center_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<center_msg_pkg::msg::Center_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__center_msg_pkg__msg__Center
    std::shared_ptr<center_msg_pkg::msg::Center_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__center_msg_pkg__msg__Center
    std::shared_ptr<center_msg_pkg::msg::Center_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Center_ & other) const
  {
    if (this->boxes != other.boxes) {
      return false;
    }
    if (this->box_num != other.box_num) {
      return false;
    }
    return true;
  }
  bool operator!=(const Center_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Center_

// alias to use template instance with default allocator
using Center =
  center_msg_pkg::msg::Center_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace center_msg_pkg

#endif  // CENTER_MSG_PKG__MSG__DETAIL__CENTER__STRUCT_HPP_
