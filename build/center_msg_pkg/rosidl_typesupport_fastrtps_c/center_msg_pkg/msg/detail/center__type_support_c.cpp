// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from center_msg_pkg:msg/Center.idl
// generated code does not contain a copyright notice
#include "center_msg_pkg/msg/detail/center__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "center_msg_pkg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "center_msg_pkg/msg/detail/center__struct.h"
#include "center_msg_pkg/msg/detail/center__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "center_msg_pkg/msg/detail/singlecenter__functions.h"  // boxes

// forward declare type support functions
size_t get_serialized_size_center_msg_pkg__msg__Singlecenter(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_center_msg_pkg__msg__Singlecenter(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, center_msg_pkg, msg, Singlecenter)();


using _Center__ros_msg_type = center_msg_pkg__msg__Center;

static bool _Center__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Center__ros_msg_type * ros_message = static_cast<const _Center__ros_msg_type *>(untyped_ros_message);
  // Field name: boxes
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, center_msg_pkg, msg, Singlecenter
      )()->data);
    size_t size = ros_message->boxes.size;
    auto array_ptr = ros_message->boxes.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  // Field name: box_num
  {
    cdr << ros_message->box_num;
  }

  return true;
}

static bool _Center__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Center__ros_msg_type * ros_message = static_cast<_Center__ros_msg_type *>(untyped_ros_message);
  // Field name: boxes
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, center_msg_pkg, msg, Singlecenter
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->boxes.data) {
      center_msg_pkg__msg__Singlecenter__Sequence__fini(&ros_message->boxes);
    }
    if (!center_msg_pkg__msg__Singlecenter__Sequence__init(&ros_message->boxes, size)) {
      fprintf(stderr, "failed to create array for field 'boxes'");
      return false;
    }
    auto array_ptr = ros_message->boxes.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  // Field name: box_num
  {
    cdr >> ros_message->box_num;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_center_msg_pkg
size_t get_serialized_size_center_msg_pkg__msg__Center(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Center__ros_msg_type * ros_message = static_cast<const _Center__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name boxes
  {
    size_t array_size = ros_message->boxes.size;
    auto array_ptr = ros_message->boxes.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_center_msg_pkg__msg__Singlecenter(
        &array_ptr[index], current_alignment);
    }
  }
  // field.name box_num
  {
    size_t item_size = sizeof(ros_message->box_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Center__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_center_msg_pkg__msg__Center(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_center_msg_pkg
size_t max_serialized_size_center_msg_pkg__msg__Center(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: boxes
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_center_msg_pkg__msg__Singlecenter(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: box_num
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = center_msg_pkg__msg__Center;
    is_plain =
      (
      offsetof(DataType, box_num) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Center__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_center_msg_pkg__msg__Center(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Center = {
  "center_msg_pkg::msg",
  "Center",
  _Center__cdr_serialize,
  _Center__cdr_deserialize,
  _Center__get_serialized_size,
  _Center__max_serialized_size
};

static rosidl_message_type_support_t _Center__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Center,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, center_msg_pkg, msg, Center)() {
  return &_Center__type_support;
}

#if defined(__cplusplus)
}
#endif
