// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rbpodo_msgs:msg/MovePbPoint.idl
// generated code does not contain a copyright notice
#include "rbpodo_msgs/msg/detail/move_pb_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rbpodo_msgs__msg__MovePbPoint__init(rbpodo_msgs__msg__MovePbPoint * msg)
{
  if (!msg) {
    return false;
  }
  // point
  // speed
  // blending_option
  // blending_value
  return true;
}

void
rbpodo_msgs__msg__MovePbPoint__fini(rbpodo_msgs__msg__MovePbPoint * msg)
{
  if (!msg) {
    return;
  }
  // point
  // speed
  // blending_option
  // blending_value
}

bool
rbpodo_msgs__msg__MovePbPoint__are_equal(const rbpodo_msgs__msg__MovePbPoint * lhs, const rbpodo_msgs__msg__MovePbPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // point
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->point[i] != rhs->point[i]) {
      return false;
    }
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // blending_option
  if (lhs->blending_option != rhs->blending_option) {
    return false;
  }
  // blending_value
  if (lhs->blending_value != rhs->blending_value) {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__msg__MovePbPoint__copy(
  const rbpodo_msgs__msg__MovePbPoint * input,
  rbpodo_msgs__msg__MovePbPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // point
  for (size_t i = 0; i < 6; ++i) {
    output->point[i] = input->point[i];
  }
  // speed
  output->speed = input->speed;
  // blending_option
  output->blending_option = input->blending_option;
  // blending_value
  output->blending_value = input->blending_value;
  return true;
}

rbpodo_msgs__msg__MovePbPoint *
rbpodo_msgs__msg__MovePbPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__MovePbPoint * msg = (rbpodo_msgs__msg__MovePbPoint *)allocator.allocate(sizeof(rbpodo_msgs__msg__MovePbPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__msg__MovePbPoint));
  bool success = rbpodo_msgs__msg__MovePbPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__msg__MovePbPoint__destroy(rbpodo_msgs__msg__MovePbPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__msg__MovePbPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__msg__MovePbPoint__Sequence__init(rbpodo_msgs__msg__MovePbPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__MovePbPoint * data = NULL;

  if (size) {
    data = (rbpodo_msgs__msg__MovePbPoint *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__msg__MovePbPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__msg__MovePbPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__msg__MovePbPoint__fini(&data[i - 1]);
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
rbpodo_msgs__msg__MovePbPoint__Sequence__fini(rbpodo_msgs__msg__MovePbPoint__Sequence * array)
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
      rbpodo_msgs__msg__MovePbPoint__fini(&array->data[i]);
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

rbpodo_msgs__msg__MovePbPoint__Sequence *
rbpodo_msgs__msg__MovePbPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__MovePbPoint__Sequence * array = (rbpodo_msgs__msg__MovePbPoint__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__msg__MovePbPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__msg__MovePbPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__msg__MovePbPoint__Sequence__destroy(rbpodo_msgs__msg__MovePbPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__msg__MovePbPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__msg__MovePbPoint__Sequence__are_equal(const rbpodo_msgs__msg__MovePbPoint__Sequence * lhs, const rbpodo_msgs__msg__MovePbPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__msg__MovePbPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__msg__MovePbPoint__Sequence__copy(
  const rbpodo_msgs__msg__MovePbPoint__Sequence * input,
  rbpodo_msgs__msg__MovePbPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__msg__MovePbPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__msg__MovePbPoint * data =
      (rbpodo_msgs__msg__MovePbPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__msg__MovePbPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__msg__MovePbPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__msg__MovePbPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
