// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from center_msg_pkg:msg/Singlecenter.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "center_msg_pkg/msg/detail/singlecenter__rosidl_typesupport_introspection_c.h"
#include "center_msg_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "center_msg_pkg/msg/detail/singlecenter__functions.h"
#include "center_msg_pkg/msg/detail/singlecenter__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  center_msg_pkg__msg__Singlecenter__init(message_memory);
}

void center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_fini_function(void * message_memory)
{
  center_msg_pkg__msg__Singlecenter__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_message_member_array[2] = {
  {
    "center_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(center_msg_pkg__msg__Singlecenter, center_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(center_msg_pkg__msg__Singlecenter, center_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_message_members = {
  "center_msg_pkg__msg",  // message namespace
  "Singlecenter",  // message name
  2,  // number of fields
  sizeof(center_msg_pkg__msg__Singlecenter),
  center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_message_member_array,  // message members
  center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_init_function,  // function to initialize message memory (memory has to be allocated)
  center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_message_type_support_handle = {
  0,
  &center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_center_msg_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, center_msg_pkg, msg, Singlecenter)() {
  if (!center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_message_type_support_handle.typesupport_identifier) {
    center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &center_msg_pkg__msg__Singlecenter__rosidl_typesupport_introspection_c__Singlecenter_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
