// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from center_msg_pkg:msg/Singlecenter.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__TRAITS_HPP_
#define CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "center_msg_pkg/msg/detail/singlecenter__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace center_msg_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Singlecenter & msg,
  std::ostream & out)
{
  out << "{";
  // member: center_x
  {
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << ", ";
  }

  // member: center_y
  {
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Singlecenter & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << "\n";
  }

  // member: center_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Singlecenter & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace center_msg_pkg

namespace rosidl_generator_traits
{

[[deprecated("use center_msg_pkg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const center_msg_pkg::msg::Singlecenter & msg,
  std::ostream & out, size_t indentation = 0)
{
  center_msg_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use center_msg_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const center_msg_pkg::msg::Singlecenter & msg)
{
  return center_msg_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<center_msg_pkg::msg::Singlecenter>()
{
  return "center_msg_pkg::msg::Singlecenter";
}

template<>
inline const char * name<center_msg_pkg::msg::Singlecenter>()
{
  return "center_msg_pkg/msg/Singlecenter";
}

template<>
struct has_fixed_size<center_msg_pkg::msg::Singlecenter>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<center_msg_pkg::msg::Singlecenter>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<center_msg_pkg::msg::Singlecenter>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__TRAITS_HPP_
