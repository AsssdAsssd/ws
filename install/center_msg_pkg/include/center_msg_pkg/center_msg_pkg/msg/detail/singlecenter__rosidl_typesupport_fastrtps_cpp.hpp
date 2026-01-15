// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from center_msg_pkg:msg/Singlecenter.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "center_msg_pkg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "center_msg_pkg/msg/detail/singlecenter__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace center_msg_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_center_msg_pkg
cdr_serialize(
  const center_msg_pkg::msg::Singlecenter & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_center_msg_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  center_msg_pkg::msg::Singlecenter & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_center_msg_pkg
get_serialized_size(
  const center_msg_pkg::msg::Singlecenter & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_center_msg_pkg
max_serialized_size_Singlecenter(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace center_msg_pkg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_center_msg_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, center_msg_pkg, msg, Singlecenter)();

#ifdef __cplusplus
}
#endif

#endif  // CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
