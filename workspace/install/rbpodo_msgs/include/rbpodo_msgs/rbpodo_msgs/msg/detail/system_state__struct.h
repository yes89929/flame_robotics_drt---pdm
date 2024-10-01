// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rbpodo_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_
#define RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SystemState in the package rbpodo_msgs.
/**
  * SystemState
  * Please check the following for more details. 
  * https://githubcom/RainbowRobotics/rbpodo/blob/main/include/rbpodo/data_type.hpp
 */
typedef struct rbpodo_msgs__msg__SystemState
{
  /// basic timer
  float time;
  /// reference (desired) joint position (unit: rad)
  float jnt_ref[6];
  /// mesaured joint position (unit: rad)
  float jnt_ang[6];
  /// mesaured joint current (unit: amp)
  float jnt_cur[6];
  /// TCP posture info based on reference-joint-angles (unit: m & rad) [x, y, z, rx, ry, rz] (orientation = EulerZYX(rz, ry, rx))
  float tcp_ref[6];
  /// TCP posture info based on encoder-joint-angles (unit: m & rad)
  float tcp_pos[6];
  /// control box analog input measurement information of each channel (unit: Voltage)
  float analog_in[4];
  /// control box analog output information of each channel (unit: Voltage)
  float analog_out[4];
  /// control box digital input measurement information of each channel
  bool digital_in[16];
  /// control box digital output information of each channel
  bool digital_out[16];
  /// measured temperature of each joint (unit: celsius)
  float jnt_temperature[6];
  /// target program counter position during function
  int32_t task_pc;
  /// target program execution number in page
  int32_t task_repeat;
  /// running program counter position
  int32_t task_run_id;
  /// current program execution number in page
  int32_t task_run_num;
  /// time since the program started (unit: second)
  int32_t task_run_time;
  /// basic state of 'Program Execution'
  int32_t task_state;
  /// default speed multiplier value of robot motion (=speed bar in UI) (value: 0 ~ 1)
  float default_speed;
  /// move (motion) state
  int32_t robot_state;
  /// information chunk to deliver various state information (power and others) It consists of a combination of bits
  int32_t information_chunk_1;
  /// basic state of each joint
  int32_t jnt_info[6];
  /// out collision detection On/Off State (true=On / false=Off)
  bool collision_detect_onoff;
  /// free-drive (Gravity-compensation) On/Off State (true=On / false=Off)
  bool is_freedrive_mode;
  /// mode of operation: Simulation mode=true / Real Robot mode=false
  bool real_vs_simulation_mode;
  /// robot arm activation (Initialization) stage info (0 -> 6)
  int8_t init_state_info;
  /// error code during the arm activation (return value for UI)
  int32_t init_error;
  /// robot-tool-flange analog input measurement information of each channel (unit: Voltage)
  float tfb_analog_in[2];
  /// robot-tool-flange digital input measurement information of each channel
  bool tfb_digital_in[2];
  /// robot-tool-flange digital output information of each channel
  bool tfb_digital_out[2];
  /// robot-Tool-Flage output voltage level (unit: Voltage)
  float tfb_voltage_out;
  /// if true, out-collision is detected
  bool op_stat_collision_occur;
  /// robot Arm device error code during operation
  int8_t op_stat_sos_flag;
  /// if true, self-collision is detected
  bool op_stat_self_collision;
  /// pause state flag
  bool op_stat_soft_estop_occur;
  /// software (kinematics) emergency stop situation
  int8_t op_stat_ems_flag;
  /// information chunk to deliver various state information (please check document)
  int32_t information_chunk_2;
  /// information chunk to deliver various state information (please check document)
  int32_t information_chunk_3;
  /// if true, detected by inbox # check-function
  bool inbox_trap_flag[2];
  /// check-function mode of Inbox #
  int8_t inbox_check_mode[2];
  /// external F/T force sensor value
  float eft[6];
  /// information chunk to deliver various state information (please check document)
  int32_t information_chunk_4;
  /// extended I/O board analog input measurement information of each channel (unit: Voltage)
  float extend_io1_analog_in[4];
  /// extended I/O board analog output information of each channel (unit: Voltage)
  float extend_io1_analog_out[4];
  /// extended I/O board digital input/output information (please check document)
  uint32_t extend_io1_digital_info;
  /// reference angle of each external-joint (auxiliary joint) (unit: rad)
  float aa_joint_ref[6];
  /// data chunk about the control box safety board
  uint32_t safety_board_stat_info;
} rbpodo_msgs__msg__SystemState;

// Struct for a sequence of rbpodo_msgs__msg__SystemState.
typedef struct rbpodo_msgs__msg__SystemState__Sequence
{
  rbpodo_msgs__msg__SystemState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rbpodo_msgs__msg__SystemState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_
