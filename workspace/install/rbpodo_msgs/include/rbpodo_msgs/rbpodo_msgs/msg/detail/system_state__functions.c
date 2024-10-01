// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rbpodo_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice
#include "rbpodo_msgs/msg/detail/system_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rbpodo_msgs__msg__SystemState__init(rbpodo_msgs__msg__SystemState * msg)
{
  if (!msg) {
    return false;
  }
  // time
  // jnt_ref
  // jnt_ang
  // jnt_cur
  // tcp_ref
  // tcp_pos
  // analog_in
  // analog_out
  // digital_in
  // digital_out
  // jnt_temperature
  // task_pc
  // task_repeat
  // task_run_id
  // task_run_num
  // task_run_time
  // task_state
  // default_speed
  // robot_state
  // information_chunk_1
  // jnt_info
  // collision_detect_onoff
  // is_freedrive_mode
  // real_vs_simulation_mode
  // init_state_info
  // init_error
  // tfb_analog_in
  // tfb_digital_in
  // tfb_digital_out
  // tfb_voltage_out
  // op_stat_collision_occur
  // op_stat_sos_flag
  // op_stat_self_collision
  // op_stat_soft_estop_occur
  // op_stat_ems_flag
  // information_chunk_2
  // information_chunk_3
  // inbox_trap_flag
  // inbox_check_mode
  // eft
  // information_chunk_4
  // extend_io1_analog_in
  // extend_io1_analog_out
  // extend_io1_digital_info
  // aa_joint_ref
  // safety_board_stat_info
  return true;
}

void
rbpodo_msgs__msg__SystemState__fini(rbpodo_msgs__msg__SystemState * msg)
{
  if (!msg) {
    return;
  }
  // time
  // jnt_ref
  // jnt_ang
  // jnt_cur
  // tcp_ref
  // tcp_pos
  // analog_in
  // analog_out
  // digital_in
  // digital_out
  // jnt_temperature
  // task_pc
  // task_repeat
  // task_run_id
  // task_run_num
  // task_run_time
  // task_state
  // default_speed
  // robot_state
  // information_chunk_1
  // jnt_info
  // collision_detect_onoff
  // is_freedrive_mode
  // real_vs_simulation_mode
  // init_state_info
  // init_error
  // tfb_analog_in
  // tfb_digital_in
  // tfb_digital_out
  // tfb_voltage_out
  // op_stat_collision_occur
  // op_stat_sos_flag
  // op_stat_self_collision
  // op_stat_soft_estop_occur
  // op_stat_ems_flag
  // information_chunk_2
  // information_chunk_3
  // inbox_trap_flag
  // inbox_check_mode
  // eft
  // information_chunk_4
  // extend_io1_analog_in
  // extend_io1_analog_out
  // extend_io1_digital_info
  // aa_joint_ref
  // safety_board_stat_info
}

bool
rbpodo_msgs__msg__SystemState__are_equal(const rbpodo_msgs__msg__SystemState * lhs, const rbpodo_msgs__msg__SystemState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time
  if (lhs->time != rhs->time) {
    return false;
  }
  // jnt_ref
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->jnt_ref[i] != rhs->jnt_ref[i]) {
      return false;
    }
  }
  // jnt_ang
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->jnt_ang[i] != rhs->jnt_ang[i]) {
      return false;
    }
  }
  // jnt_cur
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->jnt_cur[i] != rhs->jnt_cur[i]) {
      return false;
    }
  }
  // tcp_ref
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->tcp_ref[i] != rhs->tcp_ref[i]) {
      return false;
    }
  }
  // tcp_pos
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->tcp_pos[i] != rhs->tcp_pos[i]) {
      return false;
    }
  }
  // analog_in
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->analog_in[i] != rhs->analog_in[i]) {
      return false;
    }
  }
  // analog_out
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->analog_out[i] != rhs->analog_out[i]) {
      return false;
    }
  }
  // digital_in
  for (size_t i = 0; i < 16; ++i) {
    if (lhs->digital_in[i] != rhs->digital_in[i]) {
      return false;
    }
  }
  // digital_out
  for (size_t i = 0; i < 16; ++i) {
    if (lhs->digital_out[i] != rhs->digital_out[i]) {
      return false;
    }
  }
  // jnt_temperature
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->jnt_temperature[i] != rhs->jnt_temperature[i]) {
      return false;
    }
  }
  // task_pc
  if (lhs->task_pc != rhs->task_pc) {
    return false;
  }
  // task_repeat
  if (lhs->task_repeat != rhs->task_repeat) {
    return false;
  }
  // task_run_id
  if (lhs->task_run_id != rhs->task_run_id) {
    return false;
  }
  // task_run_num
  if (lhs->task_run_num != rhs->task_run_num) {
    return false;
  }
  // task_run_time
  if (lhs->task_run_time != rhs->task_run_time) {
    return false;
  }
  // task_state
  if (lhs->task_state != rhs->task_state) {
    return false;
  }
  // default_speed
  if (lhs->default_speed != rhs->default_speed) {
    return false;
  }
  // robot_state
  if (lhs->robot_state != rhs->robot_state) {
    return false;
  }
  // information_chunk_1
  if (lhs->information_chunk_1 != rhs->information_chunk_1) {
    return false;
  }
  // jnt_info
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->jnt_info[i] != rhs->jnt_info[i]) {
      return false;
    }
  }
  // collision_detect_onoff
  if (lhs->collision_detect_onoff != rhs->collision_detect_onoff) {
    return false;
  }
  // is_freedrive_mode
  if (lhs->is_freedrive_mode != rhs->is_freedrive_mode) {
    return false;
  }
  // real_vs_simulation_mode
  if (lhs->real_vs_simulation_mode != rhs->real_vs_simulation_mode) {
    return false;
  }
  // init_state_info
  if (lhs->init_state_info != rhs->init_state_info) {
    return false;
  }
  // init_error
  if (lhs->init_error != rhs->init_error) {
    return false;
  }
  // tfb_analog_in
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->tfb_analog_in[i] != rhs->tfb_analog_in[i]) {
      return false;
    }
  }
  // tfb_digital_in
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->tfb_digital_in[i] != rhs->tfb_digital_in[i]) {
      return false;
    }
  }
  // tfb_digital_out
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->tfb_digital_out[i] != rhs->tfb_digital_out[i]) {
      return false;
    }
  }
  // tfb_voltage_out
  if (lhs->tfb_voltage_out != rhs->tfb_voltage_out) {
    return false;
  }
  // op_stat_collision_occur
  if (lhs->op_stat_collision_occur != rhs->op_stat_collision_occur) {
    return false;
  }
  // op_stat_sos_flag
  if (lhs->op_stat_sos_flag != rhs->op_stat_sos_flag) {
    return false;
  }
  // op_stat_self_collision
  if (lhs->op_stat_self_collision != rhs->op_stat_self_collision) {
    return false;
  }
  // op_stat_soft_estop_occur
  if (lhs->op_stat_soft_estop_occur != rhs->op_stat_soft_estop_occur) {
    return false;
  }
  // op_stat_ems_flag
  if (lhs->op_stat_ems_flag != rhs->op_stat_ems_flag) {
    return false;
  }
  // information_chunk_2
  if (lhs->information_chunk_2 != rhs->information_chunk_2) {
    return false;
  }
  // information_chunk_3
  if (lhs->information_chunk_3 != rhs->information_chunk_3) {
    return false;
  }
  // inbox_trap_flag
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->inbox_trap_flag[i] != rhs->inbox_trap_flag[i]) {
      return false;
    }
  }
  // inbox_check_mode
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->inbox_check_mode[i] != rhs->inbox_check_mode[i]) {
      return false;
    }
  }
  // eft
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->eft[i] != rhs->eft[i]) {
      return false;
    }
  }
  // information_chunk_4
  if (lhs->information_chunk_4 != rhs->information_chunk_4) {
    return false;
  }
  // extend_io1_analog_in
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->extend_io1_analog_in[i] != rhs->extend_io1_analog_in[i]) {
      return false;
    }
  }
  // extend_io1_analog_out
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->extend_io1_analog_out[i] != rhs->extend_io1_analog_out[i]) {
      return false;
    }
  }
  // extend_io1_digital_info
  if (lhs->extend_io1_digital_info != rhs->extend_io1_digital_info) {
    return false;
  }
  // aa_joint_ref
  for (size_t i = 0; i < 6; ++i) {
    if (lhs->aa_joint_ref[i] != rhs->aa_joint_ref[i]) {
      return false;
    }
  }
  // safety_board_stat_info
  if (lhs->safety_board_stat_info != rhs->safety_board_stat_info) {
    return false;
  }
  return true;
}

bool
rbpodo_msgs__msg__SystemState__copy(
  const rbpodo_msgs__msg__SystemState * input,
  rbpodo_msgs__msg__SystemState * output)
{
  if (!input || !output) {
    return false;
  }
  // time
  output->time = input->time;
  // jnt_ref
  for (size_t i = 0; i < 6; ++i) {
    output->jnt_ref[i] = input->jnt_ref[i];
  }
  // jnt_ang
  for (size_t i = 0; i < 6; ++i) {
    output->jnt_ang[i] = input->jnt_ang[i];
  }
  // jnt_cur
  for (size_t i = 0; i < 6; ++i) {
    output->jnt_cur[i] = input->jnt_cur[i];
  }
  // tcp_ref
  for (size_t i = 0; i < 6; ++i) {
    output->tcp_ref[i] = input->tcp_ref[i];
  }
  // tcp_pos
  for (size_t i = 0; i < 6; ++i) {
    output->tcp_pos[i] = input->tcp_pos[i];
  }
  // analog_in
  for (size_t i = 0; i < 4; ++i) {
    output->analog_in[i] = input->analog_in[i];
  }
  // analog_out
  for (size_t i = 0; i < 4; ++i) {
    output->analog_out[i] = input->analog_out[i];
  }
  // digital_in
  for (size_t i = 0; i < 16; ++i) {
    output->digital_in[i] = input->digital_in[i];
  }
  // digital_out
  for (size_t i = 0; i < 16; ++i) {
    output->digital_out[i] = input->digital_out[i];
  }
  // jnt_temperature
  for (size_t i = 0; i < 6; ++i) {
    output->jnt_temperature[i] = input->jnt_temperature[i];
  }
  // task_pc
  output->task_pc = input->task_pc;
  // task_repeat
  output->task_repeat = input->task_repeat;
  // task_run_id
  output->task_run_id = input->task_run_id;
  // task_run_num
  output->task_run_num = input->task_run_num;
  // task_run_time
  output->task_run_time = input->task_run_time;
  // task_state
  output->task_state = input->task_state;
  // default_speed
  output->default_speed = input->default_speed;
  // robot_state
  output->robot_state = input->robot_state;
  // information_chunk_1
  output->information_chunk_1 = input->information_chunk_1;
  // jnt_info
  for (size_t i = 0; i < 6; ++i) {
    output->jnt_info[i] = input->jnt_info[i];
  }
  // collision_detect_onoff
  output->collision_detect_onoff = input->collision_detect_onoff;
  // is_freedrive_mode
  output->is_freedrive_mode = input->is_freedrive_mode;
  // real_vs_simulation_mode
  output->real_vs_simulation_mode = input->real_vs_simulation_mode;
  // init_state_info
  output->init_state_info = input->init_state_info;
  // init_error
  output->init_error = input->init_error;
  // tfb_analog_in
  for (size_t i = 0; i < 2; ++i) {
    output->tfb_analog_in[i] = input->tfb_analog_in[i];
  }
  // tfb_digital_in
  for (size_t i = 0; i < 2; ++i) {
    output->tfb_digital_in[i] = input->tfb_digital_in[i];
  }
  // tfb_digital_out
  for (size_t i = 0; i < 2; ++i) {
    output->tfb_digital_out[i] = input->tfb_digital_out[i];
  }
  // tfb_voltage_out
  output->tfb_voltage_out = input->tfb_voltage_out;
  // op_stat_collision_occur
  output->op_stat_collision_occur = input->op_stat_collision_occur;
  // op_stat_sos_flag
  output->op_stat_sos_flag = input->op_stat_sos_flag;
  // op_stat_self_collision
  output->op_stat_self_collision = input->op_stat_self_collision;
  // op_stat_soft_estop_occur
  output->op_stat_soft_estop_occur = input->op_stat_soft_estop_occur;
  // op_stat_ems_flag
  output->op_stat_ems_flag = input->op_stat_ems_flag;
  // information_chunk_2
  output->information_chunk_2 = input->information_chunk_2;
  // information_chunk_3
  output->information_chunk_3 = input->information_chunk_3;
  // inbox_trap_flag
  for (size_t i = 0; i < 2; ++i) {
    output->inbox_trap_flag[i] = input->inbox_trap_flag[i];
  }
  // inbox_check_mode
  for (size_t i = 0; i < 2; ++i) {
    output->inbox_check_mode[i] = input->inbox_check_mode[i];
  }
  // eft
  for (size_t i = 0; i < 6; ++i) {
    output->eft[i] = input->eft[i];
  }
  // information_chunk_4
  output->information_chunk_4 = input->information_chunk_4;
  // extend_io1_analog_in
  for (size_t i = 0; i < 4; ++i) {
    output->extend_io1_analog_in[i] = input->extend_io1_analog_in[i];
  }
  // extend_io1_analog_out
  for (size_t i = 0; i < 4; ++i) {
    output->extend_io1_analog_out[i] = input->extend_io1_analog_out[i];
  }
  // extend_io1_digital_info
  output->extend_io1_digital_info = input->extend_io1_digital_info;
  // aa_joint_ref
  for (size_t i = 0; i < 6; ++i) {
    output->aa_joint_ref[i] = input->aa_joint_ref[i];
  }
  // safety_board_stat_info
  output->safety_board_stat_info = input->safety_board_stat_info;
  return true;
}

rbpodo_msgs__msg__SystemState *
rbpodo_msgs__msg__SystemState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__SystemState * msg = (rbpodo_msgs__msg__SystemState *)allocator.allocate(sizeof(rbpodo_msgs__msg__SystemState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rbpodo_msgs__msg__SystemState));
  bool success = rbpodo_msgs__msg__SystemState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rbpodo_msgs__msg__SystemState__destroy(rbpodo_msgs__msg__SystemState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rbpodo_msgs__msg__SystemState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rbpodo_msgs__msg__SystemState__Sequence__init(rbpodo_msgs__msg__SystemState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__SystemState * data = NULL;

  if (size) {
    data = (rbpodo_msgs__msg__SystemState *)allocator.zero_allocate(size, sizeof(rbpodo_msgs__msg__SystemState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rbpodo_msgs__msg__SystemState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rbpodo_msgs__msg__SystemState__fini(&data[i - 1]);
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
rbpodo_msgs__msg__SystemState__Sequence__fini(rbpodo_msgs__msg__SystemState__Sequence * array)
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
      rbpodo_msgs__msg__SystemState__fini(&array->data[i]);
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

rbpodo_msgs__msg__SystemState__Sequence *
rbpodo_msgs__msg__SystemState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rbpodo_msgs__msg__SystemState__Sequence * array = (rbpodo_msgs__msg__SystemState__Sequence *)allocator.allocate(sizeof(rbpodo_msgs__msg__SystemState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rbpodo_msgs__msg__SystemState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rbpodo_msgs__msg__SystemState__Sequence__destroy(rbpodo_msgs__msg__SystemState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rbpodo_msgs__msg__SystemState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rbpodo_msgs__msg__SystemState__Sequence__are_equal(const rbpodo_msgs__msg__SystemState__Sequence * lhs, const rbpodo_msgs__msg__SystemState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rbpodo_msgs__msg__SystemState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rbpodo_msgs__msg__SystemState__Sequence__copy(
  const rbpodo_msgs__msg__SystemState__Sequence * input,
  rbpodo_msgs__msg__SystemState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rbpodo_msgs__msg__SystemState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rbpodo_msgs__msg__SystemState * data =
      (rbpodo_msgs__msg__SystemState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rbpodo_msgs__msg__SystemState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rbpodo_msgs__msg__SystemState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rbpodo_msgs__msg__SystemState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
