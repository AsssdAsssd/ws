// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from center_msg_pkg:msg/Singlecenter.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__STRUCT_H_
#define CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Singlecenter in the package center_msg_pkg.
typedef struct center_msg_pkg__msg__Singlecenter
{
  float center_x;
  float center_y;
} center_msg_pkg__msg__Singlecenter;

// Struct for a sequence of center_msg_pkg__msg__Singlecenter.
typedef struct center_msg_pkg__msg__Singlecenter__Sequence
{
  center_msg_pkg__msg__Singlecenter * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} center_msg_pkg__msg__Singlecenter__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__STRUCT_H_
