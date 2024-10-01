// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rbpodo_msgs:msg/MoveJb2Point.idl
// generated code does not contain a copyright notice
#include "rbpodo_msgs/msg/detail/move_jb2_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rbpodo_msgs__msg__MoveJb2Point__init(rbpodo_msgs__msg__MoveJb2Point * msg)
{
  if (!msg) {
    return false;
  }
  // joint
  // speed
  // acceleration
  // blending_value
  return true;
}

void
rbpodo_msgs__msg__MoveJb2Point__fini(rbpodo_msgs__msg__MoveJb2Point * msg)
{
  if (!msg) {
    return;
  }
  // joint
  // speed
  // acceleration
  // blending_value
}

bool
rbpodo_msgs__msg__MoveJb2Point__are_equal(const rbpodo_msgs__msg__MoveJb2Point * lhs, const rbpodo_msgs__msg__MoveJb2Point * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->joint[i] != rhs->joint[i]) {
      return false;
    }
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // acceleration
  if (lhs->acceleration != rhs->acceleration) {
    return false;
  }
  // blending_value
  if (lhs->blending_value != rhs->blending_value) {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__msg__MoveJb2Point__copy(
  const rbpodo_msgs__msg__MoveJb2Point * input,
  rbpodo_msgs__msg__MoveJb2Point * output)
{
  if (!input || !output) {
    return false;
  }
  // joint
  for (size_t i = 0; i < 6; ++i) {
    output->joint[i] = input->joint[i];
  }
  // speed
  output->speed = input->speed;
  // acceleration
  output->acceleration = input->acceleration;
  // blending_value
  output->blending_value = input->blending_value;
  return true;
}

rbpodo_msgs__msg__MoveJb2Point *
rbpodo_msgs__msg__MoveJb2Point__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__MoveJb2Point * msg = (rbpodo_msgs__msg__MoveJb2Point *)allocator.allocate(sizeof(rbpodo_msgs__msg__MoveJb2Point), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__msg__MoveJb2Point));
  bool success = rbpodo_msgs__msg__MoveJb2Point__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__msg__MoveJb2Point__destroy(rbpodo_msgs__msg__MoveJb2Point * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__msg__MoveJb2Point__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__msg__MoveJb2Point__Sequence__init(rbpodo_msgs__msg__MoveJb2Point__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__MoveJb2Point * data = NULL;

  if (size) {
    data = (rbpodo_msgs__msg__MoveJb2Point *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__msg__MoveJb2Point), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__msg__MoveJb2Point__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__msg__MoveJb2Point__fini(&data[i - 1]);
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
rbpodo_msgs__msg__MoveJb2Point__Sequence__fini(rbpodo_msgs__msg__MoveJb2Point__Sequence * array)
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
      rbpodo_msgs__msg__MoveJb2Point__fini(&array->data[i]);
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

rbpodo_msgs__msg__MoveJb2Point__Sequence *
rbpodo_msgs__msg__MoveJb2Point__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__MoveJb2Point__Sequence * array = (rbpodo_msgs__msg__MoveJb2Point__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__msg__MoveJb2Point__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__msg__MoveJb2Point__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__msg__MoveJb2Point__Sequence__destroy(rbpodo_msgs__msg__MoveJb2Point__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__msg__MoveJb2Point__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__msg__MoveJb2Point__Sequence__are_equal(const rbpodo_msgs__msg__MoveJb2Point__Sequence * lhs, const rbpodo_msgs__msg__MoveJb2Point__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__msg__MoveJb2Point__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__msg__MoveJb2Point__Sequence__copy(
  const rbpodo_msgs__msg__MoveJb2Point__Sequence * input,
  rbpodo_msgs__msg__MoveJb2Point__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__msg__MoveJb2Point);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__msg__MoveJb2Point * data =
      (rbpodo_msgs__msg__MoveJb2Point *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__msg__MoveJb2Point__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__msg__MoveJb2Point__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__msg__MoveJb2Point__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
