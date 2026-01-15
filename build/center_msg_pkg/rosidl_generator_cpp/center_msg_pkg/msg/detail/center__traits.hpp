// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from center_msg_pkg:msg/Center.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__CENTER__TRAITS_HPP_
#define CENTER_MSG_PKG__MSG__DETAIL__CENTER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "center_msg_pkg/msg/detail/center__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'boxes'
#include "center_msg_pkg/msg/detail/singlecenter__traits.hpp"

namespace center_msg_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Center & msg,
  std::ostream & out)
{
  out << "{";
  // member: boxes
  {
    if (msg.boxes.size() == 0) {
      out << "boxes: []";
    } else {
      out << "boxes: [";
      size_t pending_items = msg.boxes.size();
      for (auto item : msg.boxes) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: box_num
  {
    out << "box_num: ";
    rosidl_generator_traits::value_to_yaml(msg.box_num, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Center & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: boxes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.boxes.size() == 0) {
      out << "boxes: []\n";
    } else {
      out << "boxes:\n";
      for (auto item : msg.boxes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: box_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "box_num: ";
    rosidl_generator_traits::value_to_yaml(msg.box_num, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Center & msg, bool use_flow_style = false)
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
  const center_msg_pkg::msg::Center & msg,
  std::ostream & out, size_t indentation = 0)
{
  center_msg_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use center_msg_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const center_msg_pkg::msg::Center & msg)
{
  return center_msg_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<center_msg_pkg::msg::Center>()
{
  return "center_msg_pkg::msg::Center";
}

template<>
inline const char * name<center_msg_pkg::msg::Center>()
{
  return "center_msg_pkg/msg/Center";
}

template<>
struct has_fixed_size<center_msg_pkg::msg::Center>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<center_msg_pkg::msg::Center>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<center_msg_pkg::msg::Center>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CENTER_MSG_PKG__MSG__DETAIL__CENTER__TRAITS_HPP_
