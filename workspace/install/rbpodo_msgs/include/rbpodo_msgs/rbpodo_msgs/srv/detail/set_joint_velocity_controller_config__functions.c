// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rbpodo_msgs:srv/SetJointVelocityControllerConfig.idl
// generated code does not contain a copyright notice
#include "rbpodo_msgs/srv/detail/set_joint_velocity_controller_config__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__init(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * msg)
{
  if (!msg) {
    return false;
  }
  // t1
  // t2
  // gain
  // alpha
  return true;
}

void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__fini(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * msg)
{
  if (!msg) {
    return;
  }
  // t1
  // t2
  // gain
  // alpha
}

bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__are_equal(const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * lhs, const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // t1
  if (lhs->t1 != rhs->t1) {
    return false;
  }
  // t2
  if (lhs->t2 != rhs->t2) {
    return false;
  }
  // gain
  if (lhs->gain != rhs->gain) {
    return false;
  }
  // alpha
  if (lhs->alpha != rhs->alpha) {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__copy(
  const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * input,
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // t1
  output->t1 = input->t1;
  // t2
  output->t2 = input->t2;
  // gain
  output->gain = input->gain;
  // alpha
  output->alpha = input->alpha;
  return true;
}

rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request *
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * msg = (rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request *)allocator.allocate(sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request));
  bool success = rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__destroy(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__init(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * data = NULL;

  if (size) {
    data = (rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__fini(&data[i - 1]);
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
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__fini(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * array)
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
      rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__fini(&array->data[i]);
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

rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence *
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * array = (rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__destroy(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__are_equal(const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * lhs, const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence__copy(
  const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * input,
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request * data =
      (rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__srv__SetJointVelocityControllerConfig_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__init(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__fini(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__are_equal(const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * lhs, const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * rhs)
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
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__copy(
  const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * input,
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response *
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * msg = (rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response *)allocator.allocate(sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response));
  bool success = rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__destroy(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__init(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * data = NULL;

  if (size) {
    data = (rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__fini(&data[i - 1]);
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
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__fini(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * array)
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
      rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__fini(&array->data[i]);
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

rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence *
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * array = (rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__destroy(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__are_equal(const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * lhs, const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence__copy(
  const rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * input,
  rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response * data =
      (rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__srv__SetJointVelocityControllerConfig_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
