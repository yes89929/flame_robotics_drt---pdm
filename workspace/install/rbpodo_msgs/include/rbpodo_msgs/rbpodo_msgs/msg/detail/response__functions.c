// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rbpodo_msgs:msg/Response.idl
// generated code does not contain a copyright notice
#include "rbpodo_msgs/msg/detail/response__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `category`
// Member `msg`
// Member `error`
#include "rosidl_runtime_c/string_functions.h"

bool
rbpodo_msgs__msg__Response__init(rbpodo_msgs__msg__Response * msg)
{
  if (!msg) {
    return false;
  }
  // type
  // category
  if (!rosidl_runtime_c__String__init(&msg->category)) {
    rbpodo_msgs__msg__Response__fini(msg);
    return false;
  }
  // msg
  if (!rosidl_runtime_c__String__init(&msg->msg)) {
    rbpodo_msgs__msg__Response__fini(msg);
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__init(&msg->error)) {
    rbpodo_msgs__msg__Response__fini(msg);
    return false;
  }
  return true;
}

void
rbpodo_msgs__msg__Response__fini(rbpodo_msgs__msg__Response * msg)
{
  if (!msg) {
    return;
  }
  // type
  // category
  rosidl_runtime_c__String__fini(&msg->category);
  // msg
  rosidl_runtime_c__String__fini(&msg->msg);
  // error
  rosidl_runtime_c__String__fini(&msg->error);
}

bool
rbpodo_msgs__msg__Response__are_equal(const rbpodo_msgs__msg__Response * lhs, const rbpodo_msgs__msg__Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // category
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->category), &(rhs->category)))
  {
    return false;
  }
  // msg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->msg), &(rhs->msg)))
  {
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error), &(rhs->error)))
  {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__msg__Response__copy(
  const rbpodo_msgs__msg__Response * input,
  rbpodo_msgs__msg__Response * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  // category
  if (!rosidl_runtime_c__String__copy(
      &(input->category), &(output->category)))
  {
    return false;
  }
  // msg
  if (!rosidl_runtime_c__String__copy(
      &(input->msg), &(output->msg)))
  {
    return false;
  }
  // error
  if (!rosidl_runtime_c__String__copy(
      &(input->error), &(output->error)))
  {
    return false;
  }
  return true;
}

rbpodo_msgs__msg__Response *
rbpodo_msgs__msg__Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__Response * msg = (rbpodo_msgs__msg__Response *)allocator.allocate(sizeof(rbpodo_msgs__msg__Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__msg__Response));
  bool success = rbpodo_msgs__msg__Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__msg__Response__destroy(rbpodo_msgs__msg__Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__msg__Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__msg__Response__Sequence__init(rbpodo_msgs__msg__Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__Response * data = NULL;

  if (size) {
    data = (rbpodo_msgs__msg__Response *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__msg__Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__msg__Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__msg__Response__fini(&data[i - 1]);
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
rbpodo_msgs__msg__Response__Sequence__fini(rbpodo_msgs__msg__Response__Sequence * array)
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
      rbpodo_msgs__msg__Response__fini(&array->data[i]);
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

rbpodo_msgs__msg__Response__Sequence *
rbpodo_msgs__msg__Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__Response__Sequence * array = (rbpodo_msgs__msg__Response__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__msg__Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__msg__Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__msg__Response__Sequence__destroy(rbpodo_msgs__msg__Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__msg__Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__msg__Response__Sequence__are_equal(const rbpodo_msgs__msg__Response__Sequence * lhs, const rbpodo_msgs__msg__Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__msg__Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__msg__Response__Sequence__copy(
  const rbpodo_msgs__msg__Response__Sequence * input,
  rbpodo_msgs__msg__Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__msg__Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__msg__Response * data =
      (rbpodo_msgs__msg__Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__msg__Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__msg__Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__msg__Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
