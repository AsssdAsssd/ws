// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from center_msg_pkg:msg/Center.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__CENTER__FUNCTIONS_H_
#define CENTER_MSG_PKG__MSG__DETAIL__CENTER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "center_msg_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "center_msg_pkg/msg/detail/center__struct.h"

/// Initialize msg/Center message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * center_msg_pkg__msg__Center
 * )) before or use
 * center_msg_pkg__msg__Center__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Center__init(center_msg_pkg__msg__Center * msg);

/// Finalize msg/Center message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
void
center_msg_pkg__msg__Center__fini(center_msg_pkg__msg__Center * msg);

/// Create msg/Center message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * center_msg_pkg__msg__Center__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
center_msg_pkg__msg__Center *
center_msg_pkg__msg__Center__create();

/// Destroy msg/Center message.
/**
 * It calls
 * center_msg_pkg__msg__Center__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
void
center_msg_pkg__msg__Center__destroy(center_msg_pkg__msg__Center * msg);

/// Check for msg/Center message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Center__are_equal(const center_msg_pkg__msg__Center * lhs, const center_msg_pkg__msg__Center * rhs);

/// Copy a msg/Center message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Center__copy(
  const center_msg_pkg__msg__Center * input,
  center_msg_pkg__msg__Center * output);

/// Initialize array of msg/Center messages.
/**
 * It allocates the memory for the number of elements and calls
 * center_msg_pkg__msg__Center__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Center__Sequence__init(center_msg_pkg__msg__Center__Sequence * array, size_t size);

/// Finalize array of msg/Center messages.
/**
 * It calls
 * center_msg_pkg__msg__Center__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
void
center_msg_pkg__msg__Center__Sequence__fini(center_msg_pkg__msg__Center__Sequence * array);

/// Create array of msg/Center messages.
/**
 * It allocates the memory for the array and calls
 * center_msg_pkg__msg__Center__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
center_msg_pkg__msg__Center__Sequence *
center_msg_pkg__msg__Center__Sequence__create(size_t size);

/// Destroy array of msg/Center messages.
/**
 * It calls
 * center_msg_pkg__msg__Center__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
void
center_msg_pkg__msg__Center__Sequence__destroy(center_msg_pkg__msg__Center__Sequence * array);

/// Check for msg/Center message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Center__Sequence__are_equal(const center_msg_pkg__msg__Center__Sequence * lhs, const center_msg_pkg__msg__Center__Sequence * rhs);

/// Copy an array of msg/Center messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Center__Sequence__copy(
  const center_msg_pkg__msg__Center__Sequence * input,
  center_msg_pkg__msg__Center__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CENTER_MSG_PKG__MSG__DETAIL__CENTER__FUNCTIONS_H_
