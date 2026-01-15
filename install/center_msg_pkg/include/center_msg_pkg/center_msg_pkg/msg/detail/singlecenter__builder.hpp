// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from center_msg_pkg:msg/Singlecenter.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__BUILDER_HPP_
#define CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "center_msg_pkg/msg/detail/singlecenter__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace center_msg_pkg
{

namespace msg
{

namespace builder
{

class Init_Singlecenter_center_y
{
public:
  explicit Init_Singlecenter_center_y(::center_msg_pkg::msg::Singlecenter & msg)
  : msg_(msg)
  {}
  ::center_msg_pkg::msg::Singlecenter center_y(::center_msg_pkg::msg::Singlecenter::_center_y_type arg)
  {
    msg_.center_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::center_msg_pkg::msg::Singlecenter msg_;
};

class Init_Singlecenter_center_x
{
public:
  Init_Singlecenter_center_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Singlecenter_center_y center_x(::center_msg_pkg::msg::Singlecenter::_center_x_type arg)
  {
    msg_.center_x = std::move(arg);
    return Init_Singlecenter_center_y(msg_);
  }

private:
  ::center_msg_pkg::msg::Singlecenter msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::center_msg_pkg::msg::Singlecenter>()
{
  return center_msg_pkg::msg::builder::Init_Singlecenter_center_x();
}

}  // namespace center_msg_pkg

#endif  // CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__BUILDER_HPP_
