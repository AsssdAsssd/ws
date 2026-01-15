// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from center_msg_pkg:msg/Center.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__CENTER__STRUCT_H_
#define CENTER_MSG_PKG__MSG__DETAIL__CENTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'boxes'
#include "center_msg_pkg/msg/detail/singlecenter__struct.h"

/// Struct defined in msg/Center in the package center_msg_pkg.
typedef struct center_msg_pkg__msg__Center
{
  center_msg_pkg__msg__Singlecenter__Sequence boxes;
  uint32_t box_num;
} center_msg_pkg__msg__Center;

// Struct for a sequence of center_msg_pkg__msg__Center.
typedef struct center_msg_pkg__msg__Center__Sequence
{
  center_msg_pkg__msg__Center * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} center_msg_pkg__msg__Center__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CENTER_MSG_PKG__MSG__DETAIL__CENTER__STRUCT_H_
