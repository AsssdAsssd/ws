// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from center_msg_pkg:msg/Singlecenter.idl
// generated code does not contain a copyright notice

#ifndef CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__FUNCTIONS_H_
#define CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "center_msg_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "center_msg_pkg/msg/detail/singlecenter__struct.h"

/// Initialize msg/Singlecenter message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * center_msg_pkg__msg__Singlecenter
 * )) before or use
 * center_msg_pkg__msg__Singlecenter__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Singlecenter__init(center_msg_pkg__msg__Singlecenter * msg);

/// Finalize msg/Singlecenter message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
void
center_msg_pkg__msg__Singlecenter__fini(center_msg_pkg__msg__Singlecenter * msg);

/// Create msg/Singlecenter message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * center_msg_pkg__msg__Singlecenter__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
center_msg_pkg__msg__Singlecenter *
center_msg_pkg__msg__Singlecenter__create();

/// Destroy msg/Singlecenter message.
/**
 * It calls
 * center_msg_pkg__msg__Singlecenter__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
void
center_msg_pkg__msg__Singlecenter__destroy(center_msg_pkg__msg__Singlecenter * msg);

/// Check for msg/Singlecenter message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Singlecenter__are_equal(const center_msg_pkg__msg__Singlecenter * lhs, const center_msg_pkg__msg__Singlecenter * rhs);

/// Copy a msg/Singlecenter message.
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
center_msg_pkg__msg__Singlecenter__copy(
  const center_msg_pkg__msg__Singlecenter * input,
  center_msg_pkg__msg__Singlecenter * output);

/// Initialize array of msg/Singlecenter messages.
/**
 * It allocates the memory for the number of elements and calls
 * center_msg_pkg__msg__Singlecenter__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Singlecenter__Sequence__init(center_msg_pkg__msg__Singlecenter__Sequence * array, size_t size);

/// Finalize array of msg/Singlecenter messages.
/**
 * It calls
 * center_msg_pkg__msg__Singlecenter__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
void
center_msg_pkg__msg__Singlecenter__Sequence__fini(center_msg_pkg__msg__Singlecenter__Sequence * array);

/// Create array of msg/Singlecenter messages.
/**
 * It allocates the memory for the array and calls
 * center_msg_pkg__msg__Singlecenter__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
center_msg_pkg__msg__Singlecenter__Sequence *
center_msg_pkg__msg__Singlecenter__Sequence__create(size_t size);

/// Destroy array of msg/Singlecenter messages.
/**
 * It calls
 * center_msg_pkg__msg__Singlecenter__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
void
center_msg_pkg__msg__Singlecenter__Sequence__destroy(center_msg_pkg__msg__Singlecenter__Sequence * array);

/// Check for msg/Singlecenter message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_center_msg_pkg
bool
center_msg_pkg__msg__Singlecenter__Sequence__are_equal(const center_msg_pkg__msg__Singlecenter__Sequence * lhs, const center_msg_pkg__msg__Singlecenter__Sequence * rhs);

/// Copy an array of msg/Singlecenter messages.
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
center_msg_pkg__msg__Singlecenter__Sequence__copy(
  const center_msg_pkg__msg__Singlecenter__Sequence * input,
  center_msg_pkg__msg__Singlecenter__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CENTER_MSG_PKG__MSG__DETAIL__SINGLECENTER__FUNCTIONS_H_
