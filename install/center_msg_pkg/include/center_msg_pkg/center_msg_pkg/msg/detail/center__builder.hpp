// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from center_msg_pkg:msg/Center.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__CENTER__BUILDER_HPP_
#define CENTER_MSG_PKG__MSG__DETAIL__CENTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "center_msg_pkg/msg/detail/center__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace center_msg_pkg
{

namespace msg
{

namespace builder
{

class Init_Center_box_num
{
public:
  explicit Init_Center_box_num(::center_msg_pkg::msg::Center & msg)
  : msg_(msg)
  {}
  ::center_msg_pkg::msg::Center box_num(::center_msg_pkg::msg::Center::_box_num_type arg)
  {
    msg_.box_num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::center_msg_pkg::msg::Center msg_;
};

class Init_Center_boxes
{
public:
  Init_Center_boxes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Center_box_num boxes(::center_msg_pkg::msg::Center::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return Init_Center_box_num(msg_);
  }

private:
  ::center_msg_pkg::msg::Center msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::center_msg_pkg::msg::Center>()
{
  return center_msg_pkg::msg::builder::Init_Center_boxes();
}

}  // namespace center_msg_pkg

#endif  // CENTER_MSG_PKG__MSG__DETAIL__CENTER__BUILDER_HPP_
