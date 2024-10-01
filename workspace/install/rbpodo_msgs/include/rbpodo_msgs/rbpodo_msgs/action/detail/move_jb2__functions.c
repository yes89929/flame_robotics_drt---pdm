// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rbpodo_msgs:action/MoveJb2.idl
// generated code does not contain a copyright notice
#include "rbpodo_msgs/action/detail/move_jb2__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `points`
#include "rbpodo_msgs/msg/detail/move_jb2_point__functions.h"

bool
rbpodo_msgs__action__MoveJb2_Goal__init(rbpodo_msgs__action__MoveJb2_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // points
  if (!rbpodo_msgs__msg__MoveJb2Point__Sequence__init(&msg->points, 0)) {
    rbpodo_msgs__action__MoveJb2_Goal__fini(msg);
    return false;
  }
  // time_for_waiting_start
  return true;
}

void
rbpodo_msgs__action__MoveJb2_Goal__fini(rbpodo_msgs__action__MoveJb2_Goal * msg)
{
  if (!msg) {
    return;
  }
  // points
  rbpodo_msgs__msg__MoveJb2Point__Sequence__fini(&msg->points);
  // time_for_waiting_start
}

bool
rbpodo_msgs__action__MoveJb2_Goal__are_equal(const rbpodo_msgs__action__MoveJb2_Goal * lhs, const rbpodo_msgs__action__MoveJb2_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // points
  if (!rbpodo_msgs__msg__MoveJb2Point__Sequence__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  // time_for_waiting_start
  if (lhs->time_for_waiting_start != rhs->time_for_waiting_start) {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_Goal__copy(
  const rbpodo_msgs__action__MoveJb2_Goal * input,
  rbpodo_msgs__action__MoveJb2_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // points
  if (!rbpodo_msgs__msg__MoveJb2Point__Sequence__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  // time_for_waiting_start
  output->time_for_waiting_start = input->time_for_waiting_start;
  return true;
}

rbpodo_msgs__action__MoveJb2_Goal *
rbpodo_msgs__action__MoveJb2_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Goal * msg = (rbpodo_msgs__action__MoveJb2_Goal *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__action__MoveJb2_Goal));
  bool success = rbpodo_msgs__action__MoveJb2_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__action__MoveJb2_Goal__destroy(rbpodo_msgs__action__MoveJb2_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__action__MoveJb2_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__action__MoveJb2_Goal__Sequence__init(rbpodo_msgs__action__MoveJb2_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Goal * data = NULL;

  if (size) {
    data = (rbpodo_msgs__action__MoveJb2_Goal *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__action__MoveJb2_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__action__MoveJb2_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__action__MoveJb2_Goal__fini(&data[i - 1]);
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
rbpodo_msgs__action__MoveJb2_Goal__Sequence__fini(rbpodo_msgs__action__MoveJb2_Goal__Sequence * array)
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
      rbpodo_msgs__action__MoveJb2_Goal__fini(&array->data[i]);
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

rbpodo_msgs__action__MoveJb2_Goal__Sequence *
rbpodo_msgs__action__MoveJb2_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Goal__Sequence * array = (rbpodo_msgs__action__MoveJb2_Goal__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__action__MoveJb2_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__action__MoveJb2_Goal__Sequence__destroy(rbpodo_msgs__action__MoveJb2_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__action__MoveJb2_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__action__MoveJb2_Goal__Sequence__are_equal(const rbpodo_msgs__action__MoveJb2_Goal__Sequence * lhs, const rbpodo_msgs__action__MoveJb2_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_Goal__Sequence__copy(
  const rbpodo_msgs__action__MoveJb2_Goal__Sequence * input,
  rbpodo_msgs__action__MoveJb2_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__action__MoveJb2_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__action__MoveJb2_Goal * data =
      (rbpodo_msgs__action__MoveJb2_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__action__MoveJb2_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__action__MoveJb2_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
rbpodo_msgs__action__MoveJb2_Result__init(rbpodo_msgs__action__MoveJb2_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
rbpodo_msgs__action__MoveJb2_Result__fini(rbpodo_msgs__action__MoveJb2_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
rbpodo_msgs__action__MoveJb2_Result__are_equal(const rbpodo_msgs__action__MoveJb2_Result * lhs, const rbpodo_msgs__action__MoveJb2_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_Result__copy(
  const rbpodo_msgs__action__MoveJb2_Result * input,
  rbpodo_msgs__action__MoveJb2_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

rbpodo_msgs__action__MoveJb2_Result *
rbpodo_msgs__action__MoveJb2_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Result * msg = (rbpodo_msgs__action__MoveJb2_Result *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__action__MoveJb2_Result));
  bool success = rbpodo_msgs__action__MoveJb2_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__action__MoveJb2_Result__destroy(rbpodo_msgs__action__MoveJb2_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__action__MoveJb2_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__action__MoveJb2_Result__Sequence__init(rbpodo_msgs__action__MoveJb2_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Result * data = NULL;

  if (size) {
    data = (rbpodo_msgs__action__MoveJb2_Result *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__action__MoveJb2_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__action__MoveJb2_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__action__MoveJb2_Result__fini(&data[i - 1]);
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
rbpodo_msgs__action__MoveJb2_Result__Sequence__fini(rbpodo_msgs__action__MoveJb2_Result__Sequence * array)
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
      rbpodo_msgs__action__MoveJb2_Result__fini(&array->data[i]);
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

rbpodo_msgs__action__MoveJb2_Result__Sequence *
rbpodo_msgs__action__MoveJb2_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Result__Sequence * array = (rbpodo_msgs__action__MoveJb2_Result__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__action__MoveJb2_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__action__MoveJb2_Result__Sequence__destroy(rbpodo_msgs__action__MoveJb2_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__action__MoveJb2_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__action__MoveJb2_Result__Sequence__are_equal(const rbpodo_msgs__action__MoveJb2_Result__Sequence * lhs, const rbpodo_msgs__action__MoveJb2_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_Result__Sequence__copy(
  const rbpodo_msgs__action__MoveJb2_Result__Sequence * input,
  rbpodo_msgs__action__MoveJb2_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__action__MoveJb2_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__action__MoveJb2_Result * data =
      (rbpodo_msgs__action__MoveJb2_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__action__MoveJb2_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__action__MoveJb2_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `state`
#include "rbpodo_msgs/msg/detail/system_state__functions.h"

bool
rbpodo_msgs__action__MoveJb2_Feedback__init(rbpodo_msgs__action__MoveJb2_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!rbpodo_msgs__msg__SystemState__init(&msg->state)) {
    rbpodo_msgs__action__MoveJb2_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
rbpodo_msgs__action__MoveJb2_Feedback__fini(rbpodo_msgs__action__MoveJb2_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // state
  rbpodo_msgs__msg__SystemState__fini(&msg->state);
}

bool
rbpodo_msgs__action__MoveJb2_Feedback__are_equal(const rbpodo_msgs__action__MoveJb2_Feedback * lhs, const rbpodo_msgs__action__MoveJb2_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (!rbpodo_msgs__msg__SystemState__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_Feedback__copy(
  const rbpodo_msgs__action__MoveJb2_Feedback * input,
  rbpodo_msgs__action__MoveJb2_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  if (!rbpodo_msgs__msg__SystemState__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  return true;
}

rbpodo_msgs__action__MoveJb2_Feedback *
rbpodo_msgs__action__MoveJb2_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Feedback * msg = (rbpodo_msgs__action__MoveJb2_Feedback *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__action__MoveJb2_Feedback));
  bool success = rbpodo_msgs__action__MoveJb2_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__action__MoveJb2_Feedback__destroy(rbpodo_msgs__action__MoveJb2_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__action__MoveJb2_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__action__MoveJb2_Feedback__Sequence__init(rbpodo_msgs__action__MoveJb2_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Feedback * data = NULL;

  if (size) {
    data = (rbpodo_msgs__action__MoveJb2_Feedback *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__action__MoveJb2_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__action__MoveJb2_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__action__MoveJb2_Feedback__fini(&data[i - 1]);
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
rbpodo_msgs__action__MoveJb2_Feedback__Sequence__fini(rbpodo_msgs__action__MoveJb2_Feedback__Sequence * array)
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
      rbpodo_msgs__action__MoveJb2_Feedback__fini(&array->data[i]);
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

rbpodo_msgs__action__MoveJb2_Feedback__Sequence *
rbpodo_msgs__action__MoveJb2_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_Feedback__Sequence * array = (rbpodo_msgs__action__MoveJb2_Feedback__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__action__MoveJb2_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__action__MoveJb2_Feedback__Sequence__destroy(rbpodo_msgs__action__MoveJb2_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__action__MoveJb2_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__action__MoveJb2_Feedback__Sequence__are_equal(const rbpodo_msgs__action__MoveJb2_Feedback__Sequence * lhs, const rbpodo_msgs__action__MoveJb2_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_Feedback__Sequence__copy(
  const rbpodo_msgs__action__MoveJb2_Feedback__Sequence * input,
  rbpodo_msgs__action__MoveJb2_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__action__MoveJb2_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__action__MoveJb2_Feedback * data =
      (rbpodo_msgs__action__MoveJb2_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__action__MoveJb2_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__action__MoveJb2_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "rbpodo_msgs/action/detail/move_jb2__functions.h"

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Request__init(rbpodo_msgs__action__MoveJb2_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    rbpodo_msgs__action__MoveJb2_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!rbpodo_msgs__action__MoveJb2_Goal__init(&msg->goal)) {
    rbpodo_msgs__action__MoveJb2_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
rbpodo_msgs__action__MoveJb2_SendGoal_Request__fini(rbpodo_msgs__action__MoveJb2_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  rbpodo_msgs__action__MoveJb2_Goal__fini(&msg->goal);
}

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Request__are_equal(const rbpodo_msgs__action__MoveJb2_SendGoal_Request * lhs, const rbpodo_msgs__action__MoveJb2_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!rbpodo_msgs__action__MoveJb2_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Request__copy(
  const rbpodo_msgs__action__MoveJb2_SendGoal_Request * input,
  rbpodo_msgs__action__MoveJb2_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!rbpodo_msgs__action__MoveJb2_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

rbpodo_msgs__action__MoveJb2_SendGoal_Request *
rbpodo_msgs__action__MoveJb2_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_SendGoal_Request * msg = (rbpodo_msgs__action__MoveJb2_SendGoal_Request *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Request));
  bool success = rbpodo_msgs__action__MoveJb2_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__action__MoveJb2_SendGoal_Request__destroy(rbpodo_msgs__action__MoveJb2_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__action__MoveJb2_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence__init(rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_SendGoal_Request * data = NULL;

  if (size) {
    data = (rbpodo_msgs__action__MoveJb2_SendGoal_Request *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__action__MoveJb2_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__action__MoveJb2_SendGoal_Request__fini(&data[i - 1]);
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
rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence__fini(rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence * array)
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
      rbpodo_msgs__action__MoveJb2_SendGoal_Request__fini(&array->data[i]);
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

rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence *
rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence * array = (rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence__destroy(rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence__are_equal(const rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence * lhs, const rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence__copy(
  const rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence * input,
  rbpodo_msgs__action__MoveJb2_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__action__MoveJb2_SendGoal_Request * data =
      (rbpodo_msgs__action__MoveJb2_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__action__MoveJb2_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__action__MoveJb2_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Response__init(rbpodo_msgs__action__MoveJb2_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    rbpodo_msgs__action__MoveJb2_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
rbpodo_msgs__action__MoveJb2_SendGoal_Response__fini(rbpodo_msgs__action__MoveJb2_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Response__are_equal(const rbpodo_msgs__action__MoveJb2_SendGoal_Response * lhs, const rbpodo_msgs__action__MoveJb2_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Response__copy(
  const rbpodo_msgs__action__MoveJb2_SendGoal_Response * input,
  rbpodo_msgs__action__MoveJb2_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

rbpodo_msgs__action__MoveJb2_SendGoal_Response *
rbpodo_msgs__action__MoveJb2_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_SendGoal_Response * msg = (rbpodo_msgs__action__MoveJb2_SendGoal_Response *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Response));
  bool success = rbpodo_msgs__action__MoveJb2_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__action__MoveJb2_SendGoal_Response__destroy(rbpodo_msgs__action__MoveJb2_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__action__MoveJb2_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence__init(rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_SendGoal_Response * data = NULL;

  if (size) {
    data = (rbpodo_msgs__action__MoveJb2_SendGoal_Response *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__action__MoveJb2_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__action__MoveJb2_SendGoal_Response__fini(&data[i - 1]);
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
rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence__fini(rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence * array)
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
      rbpodo_msgs__action__MoveJb2_SendGoal_Response__fini(&array->data[i]);
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

rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence *
rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence * array = (rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence__destroy(rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence__are_equal(const rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence * lhs, const rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence__copy(
  const rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence * input,
  rbpodo_msgs__action__MoveJb2_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__action__MoveJb2_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__action__MoveJb2_SendGoal_Response * data =
      (rbpodo_msgs__action__MoveJb2_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__action__MoveJb2_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__action__MoveJb2_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
rbpodo_msgs__action__MoveJb2_GetResult_Request__init(rbpodo_msgs__action__MoveJb2_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    rbpodo_msgs__action__MoveJb2_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
rbpodo_msgs__action__MoveJb2_GetResult_Request__fini(rbpodo_msgs__action__MoveJb2_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
rbpodo_msgs__action__MoveJb2_GetResult_Request__are_equal(const rbpodo_msgs__action__MoveJb2_GetResult_Request * lhs, const rbpodo_msgs__action__MoveJb2_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_GetResult_Request__copy(
  const rbpodo_msgs__action__MoveJb2_GetResult_Request * input,
  rbpodo_msgs__action__MoveJb2_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

rbpodo_msgs__action__MoveJb2_GetResult_Request *
rbpodo_msgs__action__MoveJb2_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_GetResult_Request * msg = (rbpodo_msgs__action__MoveJb2_GetResult_Request *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Request));
  bool success = rbpodo_msgs__action__MoveJb2_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__action__MoveJb2_GetResult_Request__destroy(rbpodo_msgs__action__MoveJb2_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__action__MoveJb2_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence__init(rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_GetResult_Request * data = NULL;

  if (size) {
    data = (rbpodo_msgs__action__MoveJb2_GetResult_Request *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__action__MoveJb2_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__action__MoveJb2_GetResult_Request__fini(&data[i - 1]);
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
rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence__fini(rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence * array)
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
      rbpodo_msgs__action__MoveJb2_GetResult_Request__fini(&array->data[i]);
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

rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence *
rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence * array = (rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence__destroy(rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence__are_equal(const rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence * lhs, const rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence__copy(
  const rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence * input,
  rbpodo_msgs__action__MoveJb2_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__action__MoveJb2_GetResult_Request * data =
      (rbpodo_msgs__action__MoveJb2_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__action__MoveJb2_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__action__MoveJb2_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "rbpodo_msgs/action/detail/move_jb2__functions.h"

bool
rbpodo_msgs__action__MoveJb2_GetResult_Response__init(rbpodo_msgs__action__MoveJb2_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!rbpodo_msgs__action__MoveJb2_Result__init(&msg->result)) {
    rbpodo_msgs__action__MoveJb2_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
rbpodo_msgs__action__MoveJb2_GetResult_Response__fini(rbpodo_msgs__action__MoveJb2_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  rbpodo_msgs__action__MoveJb2_Result__fini(&msg->result);
}

bool
rbpodo_msgs__action__MoveJb2_GetResult_Response__are_equal(const rbpodo_msgs__action__MoveJb2_GetResult_Response * lhs, const rbpodo_msgs__action__MoveJb2_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!rbpodo_msgs__action__MoveJb2_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_GetResult_Response__copy(
  const rbpodo_msgs__action__MoveJb2_GetResult_Response * input,
  rbpodo_msgs__action__MoveJb2_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!rbpodo_msgs__action__MoveJb2_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

rbpodo_msgs__action__MoveJb2_GetResult_Response *
rbpodo_msgs__action__MoveJb2_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_GetResult_Response * msg = (rbpodo_msgs__action__MoveJb2_GetResult_Response *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Response));
  bool success = rbpodo_msgs__action__MoveJb2_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__action__MoveJb2_GetResult_Response__destroy(rbpodo_msgs__action__MoveJb2_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__action__MoveJb2_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence__init(rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_GetResult_Response * data = NULL;

  if (size) {
    data = (rbpodo_msgs__action__MoveJb2_GetResult_Response *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__action__MoveJb2_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__action__MoveJb2_GetResult_Response__fini(&data[i - 1]);
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
rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence__fini(rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence * array)
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
      rbpodo_msgs__action__MoveJb2_GetResult_Response__fini(&array->data[i]);
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

rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence *
rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence * array = (rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence__destroy(rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence__are_equal(const rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence * lhs, const rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence__copy(
  const rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence * input,
  rbpodo_msgs__action__MoveJb2_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__action__MoveJb2_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__action__MoveJb2_GetResult_Response * data =
      (rbpodo_msgs__action__MoveJb2_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__action__MoveJb2_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__action__MoveJb2_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "rbpodo_msgs/action/detail/move_jb2__functions.h"

bool
rbpodo_msgs__action__MoveJb2_FeedbackMessage__init(rbpodo_msgs__action__MoveJb2_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    rbpodo_msgs__action__MoveJb2_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!rbpodo_msgs__action__MoveJb2_Feedback__init(&msg->feedback)) {
    rbpodo_msgs__action__MoveJb2_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
rbpodo_msgs__action__MoveJb2_FeedbackMessage__fini(rbpodo_msgs__action__MoveJb2_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  rbpodo_msgs__action__MoveJb2_Feedback__fini(&msg->feedback);
}

bool
rbpodo_msgs__action__MoveJb2_FeedbackMessage__are_equal(const rbpodo_msgs__action__MoveJb2_FeedbackMessage * lhs, const rbpodo_msgs__action__MoveJb2_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!rbpodo_msgs__action__MoveJb2_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_FeedbackMessage__copy(
  const rbpodo_msgs__action__MoveJb2_FeedbackMessage * input,
  rbpodo_msgs__action__MoveJb2_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!rbpodo_msgs__action__MoveJb2_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

rbpodo_msgs__action__MoveJb2_FeedbackMessage *
rbpodo_msgs__action__MoveJb2_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_FeedbackMessage * msg = (rbpodo_msgs__action__MoveJb2_FeedbackMessage *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__action__MoveJb2_FeedbackMessage));
  bool success = rbpodo_msgs__action__MoveJb2_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__action__MoveJb2_FeedbackMessage__destroy(rbpodo_msgs__action__MoveJb2_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__action__MoveJb2_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence__init(rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_FeedbackMessage * data = NULL;

  if (size) {
    data = (rbpodo_msgs__action__MoveJb2_FeedbackMessage *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__action__MoveJb2_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__action__MoveJb2_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__action__MoveJb2_FeedbackMessage__fini(&data[i - 1]);
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
rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence__fini(rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence * array)
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
      rbpodo_msgs__action__MoveJb2_FeedbackMessage__fini(&array->data[i]);
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

rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence *
rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence * array = (rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence__destroy(rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence__are_equal(const rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence * lhs, const rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence__copy(
  const rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence * input,
  rbpodo_msgs__action__MoveJb2_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__action__MoveJb2_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__action__MoveJb2_FeedbackMessage * data =
      (rbpodo_msgs__action__MoveJb2_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__action__MoveJb2_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__action__MoveJb2_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__action__MoveJb2_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
