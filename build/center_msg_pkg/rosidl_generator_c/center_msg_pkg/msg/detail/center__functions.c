// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from center_msg_pkg:msg/Center.idl
// generated code does not contain a copyright notice
#include "center_msg_pkg/msg/detail/center__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `boxes`
#include "center_msg_pkg/msg/detail/singlecenter__functions.h"

bool
center_msg_pkg__msg__Center__init(center_msg_pkg__msg__Center * msg)
{
  if (!msg) {
    return false;
  }
  // boxes
  if (!center_msg_pkg__msg__Singlecenter__Sequence__init(&msg->boxes, 0)) {
    center_msg_pkg__msg__Center__fini(msg);
    return false;
  }
  // box_num
  return true;
}

void
center_msg_pkg__msg__Center__fini(center_msg_pkg__msg__Center * msg)
{
  if (!msg) {
    return;
  }
  // boxes
  center_msg_pkg__msg__Singlecenter__Sequence__fini(&msg->boxes);
  // box_num
}

bool
center_msg_pkg__msg__Center__are_equal(const center_msg_pkg__msg__Center * lhs, const center_msg_pkg__msg__Center * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // boxes
  if (!center_msg_pkg__msg__Singlecenter__Sequence__are_equal(
      &(lhs->boxes), &(rhs->boxes)))
  {
    return false;
  }
  // box_num
  if (lhs->box_num != rhs->box_num) {
    return false;
  }
  return true;
}

bool
center_msg_pkg__msg__Center__copy(
  const center_msg_pkg__msg__Center * input,
  center_msg_pkg__msg__Center * output)
{
  if (!input || !output) {
    return false;
  }
  // boxes
  if (!center_msg_pkg__msg__Singlecenter__Sequence__copy(
      &(input->boxes), &(output->boxes)))
  {
    return false;
  }
  // box_num
  output->box_num = input->box_num;
  return true;
}

center_msg_pkg__msg__Center *
center_msg_pkg__msg__Center__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  center_msg_pkg__msg__Center * msg = (center_msg_pkg__msg__Center *)allocator.allocate(sizeof(center_msg_pkg__msg__Center), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(center_msg_pkg__msg__Center));
  bool success = center_msg_pkg__msg__Center__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
center_msg_pkg__msg__Center__destroy(center_msg_pkg__msg__Center * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    center_msg_pkg__msg__Center__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
center_msg_pkg__msg__Center__Sequence__init(center_msg_pkg__msg__Center__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  center_msg_pkg__msg__Center * data = NULL;

  if (size) {
    data = (center_msg_pkg__msg__Center *)allocator.zero_allocate(size, sizeof(center_msg_pkg__msg__Center), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = center_msg_pkg__msg__Center__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        center_msg_pkg__msg__Center__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
center_msg_pkg__msg__Center__Sequence__fini(center_msg_pkg__msg__Center__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      center_msg_pkg__msg__Center__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

center_msg_pkg__msg__Center__Sequence *
center_msg_pkg__msg__Center__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  center_msg_pkg__msg__Center__Sequence * array = (center_msg_pkg__msg__Center__Sequence *)allocator.allocate(sizeof(center_msg_pkg__msg__Center__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = center_msg_pkg__msg__Center__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
center_msg_pkg__msg__Center__Sequence__destroy(center_msg_pkg__msg__Center__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    center_msg_pkg__msg__Center__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
center_msg_pkg__msg__Center__Sequence__are_equal(const center_msg_pkg__msg__Center__Sequence * lhs, const center_msg_pkg__msg__Center__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!center_msg_pkg__msg__Center__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
center_msg_pkg__msg__Center__Sequence__copy(
  const center_msg_pkg__msg__Center__Sequence * input,
  center_msg_pkg__msg__Center__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(center_msg_pkg__msg__Center);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    center_msg_pkg__msg__Center * data =
      (center_msg_pkg__msg__Center *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!center_msg_pkg__msg__Center__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          center_msg_pkg__msg__Center__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!center_msg_pkg__msg__Center__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
