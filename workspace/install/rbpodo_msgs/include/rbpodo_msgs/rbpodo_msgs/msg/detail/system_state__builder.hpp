// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rbpodo_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_
#define RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rbpodo_msgs/msg/detail/system_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rbpodo_msgs
{

namespace msg
{

namespace builder
{

class Init_SystemState_safety_board_stat_info
{
public:
  explicit Init_SystemState_safety_board_stat_info(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  ::rbpodo_msgs::msg::SystemState safety_board_stat_info(::rbpodo_msgs::msg::SystemState::_safety_board_stat_info_type arg)
  {
    msg_.safety_board_stat_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_aa_joint_ref
{
public:
  explicit Init_SystemState_aa_joint_ref(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_safety_board_stat_info aa_joint_ref(::rbpodo_msgs::msg::SystemState::_aa_joint_ref_type arg)
  {
    msg_.aa_joint_ref = std::move(arg);
    return Init_SystemState_safety_board_stat_info(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_extend_io1_digital_info
{
public:
  explicit Init_SystemState_extend_io1_digital_info(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_aa_joint_ref extend_io1_digital_info(::rbpodo_msgs::msg::SystemState::_extend_io1_digital_info_type arg)
  {
    msg_.extend_io1_digital_info = std::move(arg);
    return Init_SystemState_aa_joint_ref(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_extend_io1_analog_out
{
public:
  explicit Init_SystemState_extend_io1_analog_out(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_extend_io1_digital_info extend_io1_analog_out(::rbpodo_msgs::msg::SystemState::_extend_io1_analog_out_type arg)
  {
    msg_.extend_io1_analog_out = std::move(arg);
    return Init_SystemState_extend_io1_digital_info(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_extend_io1_analog_in
{
public:
  explicit Init_SystemState_extend_io1_analog_in(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_extend_io1_analog_out extend_io1_analog_in(::rbpodo_msgs::msg::SystemState::_extend_io1_analog_in_type arg)
  {
    msg_.extend_io1_analog_in = std::move(arg);
    return Init_SystemState_extend_io1_analog_out(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_information_chunk_4
{
public:
  explicit Init_SystemState_information_chunk_4(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_extend_io1_analog_in information_chunk_4(::rbpodo_msgs::msg::SystemState::_information_chunk_4_type arg)
  {
    msg_.information_chunk_4 = std::move(arg);
    return Init_SystemState_extend_io1_analog_in(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_eft
{
public:
  explicit Init_SystemState_eft(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_information_chunk_4 eft(::rbpodo_msgs::msg::SystemState::_eft_type arg)
  {
    msg_.eft = std::move(arg);
    return Init_SystemState_information_chunk_4(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_inbox_check_mode
{
public:
  explicit Init_SystemState_inbox_check_mode(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_eft inbox_check_mode(::rbpodo_msgs::msg::SystemState::_inbox_check_mode_type arg)
  {
    msg_.inbox_check_mode = std::move(arg);
    return Init_SystemState_eft(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_inbox_trap_flag
{
public:
  explicit Init_SystemState_inbox_trap_flag(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_inbox_check_mode inbox_trap_flag(::rbpodo_msgs::msg::SystemState::_inbox_trap_flag_type arg)
  {
    msg_.inbox_trap_flag = std::move(arg);
    return Init_SystemState_inbox_check_mode(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_information_chunk_3
{
public:
  explicit Init_SystemState_information_chunk_3(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_inbox_trap_flag information_chunk_3(::rbpodo_msgs::msg::SystemState::_information_chunk_3_type arg)
  {
    msg_.information_chunk_3 = std::move(arg);
    return Init_SystemState_inbox_trap_flag(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_information_chunk_2
{
public:
  explicit Init_SystemState_information_chunk_2(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_information_chunk_3 information_chunk_2(::rbpodo_msgs::msg::SystemState::_information_chunk_2_type arg)
  {
    msg_.information_chunk_2 = std::move(arg);
    return Init_SystemState_information_chunk_3(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_op_stat_ems_flag
{
public:
  explicit Init_SystemState_op_stat_ems_flag(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_information_chunk_2 op_stat_ems_flag(::rbpodo_msgs::msg::SystemState::_op_stat_ems_flag_type arg)
  {
    msg_.op_stat_ems_flag = std::move(arg);
    return Init_SystemState_information_chunk_2(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_op_stat_soft_estop_occur
{
public:
  explicit Init_SystemState_op_stat_soft_estop_occur(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_op_stat_ems_flag op_stat_soft_estop_occur(::rbpodo_msgs::msg::SystemState::_op_stat_soft_estop_occur_type arg)
  {
    msg_.op_stat_soft_estop_occur = std::move(arg);
    return Init_SystemState_op_stat_ems_flag(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_op_stat_self_collision
{
public:
  explicit Init_SystemState_op_stat_self_collision(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_op_stat_soft_estop_occur op_stat_self_collision(::rbpodo_msgs::msg::SystemState::_op_stat_self_collision_type arg)
  {
    msg_.op_stat_self_collision = std::move(arg);
    return Init_SystemState_op_stat_soft_estop_occur(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_op_stat_sos_flag
{
public:
  explicit Init_SystemState_op_stat_sos_flag(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_op_stat_self_collision op_stat_sos_flag(::rbpodo_msgs::msg::SystemState::_op_stat_sos_flag_type arg)
  {
    msg_.op_stat_sos_flag = std::move(arg);
    return Init_SystemState_op_stat_self_collision(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_op_stat_collision_occur
{
public:
  explicit Init_SystemState_op_stat_collision_occur(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_op_stat_sos_flag op_stat_collision_occur(::rbpodo_msgs::msg::SystemState::_op_stat_collision_occur_type arg)
  {
    msg_.op_stat_collision_occur = std::move(arg);
    return Init_SystemState_op_stat_sos_flag(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_tfb_voltage_out
{
public:
  explicit Init_SystemState_tfb_voltage_out(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_op_stat_collision_occur tfb_voltage_out(::rbpodo_msgs::msg::SystemState::_tfb_voltage_out_type arg)
  {
    msg_.tfb_voltage_out = std::move(arg);
    return Init_SystemState_op_stat_collision_occur(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_tfb_digital_out
{
public:
  explicit Init_SystemState_tfb_digital_out(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tfb_voltage_out tfb_digital_out(::rbpodo_msgs::msg::SystemState::_tfb_digital_out_type arg)
  {
    msg_.tfb_digital_out = std::move(arg);
    return Init_SystemState_tfb_voltage_out(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_tfb_digital_in
{
public:
  explicit Init_SystemState_tfb_digital_in(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tfb_digital_out tfb_digital_in(::rbpodo_msgs::msg::SystemState::_tfb_digital_in_type arg)
  {
    msg_.tfb_digital_in = std::move(arg);
    return Init_SystemState_tfb_digital_out(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_tfb_analog_in
{
public:
  explicit Init_SystemState_tfb_analog_in(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tfb_digital_in tfb_analog_in(::rbpodo_msgs::msg::SystemState::_tfb_analog_in_type arg)
  {
    msg_.tfb_analog_in = std::move(arg);
    return Init_SystemState_tfb_digital_in(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_init_error
{
public:
  explicit Init_SystemState_init_error(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tfb_analog_in init_error(::rbpodo_msgs::msg::SystemState::_init_error_type arg)
  {
    msg_.init_error = std::move(arg);
    return Init_SystemState_tfb_analog_in(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_init_state_info
{
public:
  explicit Init_SystemState_init_state_info(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_init_error init_state_info(::rbpodo_msgs::msg::SystemState::_init_state_info_type arg)
  {
    msg_.init_state_info = std::move(arg);
    return Init_SystemState_init_error(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_real_vs_simulation_mode
{
public:
  explicit Init_SystemState_real_vs_simulation_mode(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_init_state_info real_vs_simulation_mode(::rbpodo_msgs::msg::SystemState::_real_vs_simulation_mode_type arg)
  {
    msg_.real_vs_simulation_mode = std::move(arg);
    return Init_SystemState_init_state_info(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_is_freedrive_mode
{
public:
  explicit Init_SystemState_is_freedrive_mode(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_real_vs_simulation_mode is_freedrive_mode(::rbpodo_msgs::msg::SystemState::_is_freedrive_mode_type arg)
  {
    msg_.is_freedrive_mode = std::move(arg);
    return Init_SystemState_real_vs_simulation_mode(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_collision_detect_onoff
{
public:
  explicit Init_SystemState_collision_detect_onoff(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_is_freedrive_mode collision_detect_onoff(::rbpodo_msgs::msg::SystemState::_collision_detect_onoff_type arg)
  {
    msg_.collision_detect_onoff = std::move(arg);
    return Init_SystemState_is_freedrive_mode(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_jnt_info
{
public:
  explicit Init_SystemState_jnt_info(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_collision_detect_onoff jnt_info(::rbpodo_msgs::msg::SystemState::_jnt_info_type arg)
  {
    msg_.jnt_info = std::move(arg);
    return Init_SystemState_collision_detect_onoff(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_information_chunk_1
{
public:
  explicit Init_SystemState_information_chunk_1(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_jnt_info information_chunk_1(::rbpodo_msgs::msg::SystemState::_information_chunk_1_type arg)
  {
    msg_.information_chunk_1 = std::move(arg);
    return Init_SystemState_jnt_info(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_robot_state
{
public:
  explicit Init_SystemState_robot_state(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_information_chunk_1 robot_state(::rbpodo_msgs::msg::SystemState::_robot_state_type arg)
  {
    msg_.robot_state = std::move(arg);
    return Init_SystemState_information_chunk_1(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_default_speed
{
public:
  explicit Init_SystemState_default_speed(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_robot_state default_speed(::rbpodo_msgs::msg::SystemState::_default_speed_type arg)
  {
    msg_.default_speed = std::move(arg);
    return Init_SystemState_robot_state(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_task_state
{
public:
  explicit Init_SystemState_task_state(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_default_speed task_state(::rbpodo_msgs::msg::SystemState::_task_state_type arg)
  {
    msg_.task_state = std::move(arg);
    return Init_SystemState_default_speed(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_task_run_time
{
public:
  explicit Init_SystemState_task_run_time(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_task_state task_run_time(::rbpodo_msgs::msg::SystemState::_task_run_time_type arg)
  {
    msg_.task_run_time = std::move(arg);
    return Init_SystemState_task_state(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_task_run_num
{
public:
  explicit Init_SystemState_task_run_num(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_task_run_time task_run_num(::rbpodo_msgs::msg::SystemState::_task_run_num_type arg)
  {
    msg_.task_run_num = std::move(arg);
    return Init_SystemState_task_run_time(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_task_run_id
{
public:
  explicit Init_SystemState_task_run_id(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_task_run_num task_run_id(::rbpodo_msgs::msg::SystemState::_task_run_id_type arg)
  {
    msg_.task_run_id = std::move(arg);
    return Init_SystemState_task_run_num(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_task_repeat
{
public:
  explicit Init_SystemState_task_repeat(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_task_run_id task_repeat(::rbpodo_msgs::msg::SystemState::_task_repeat_type arg)
  {
    msg_.task_repeat = std::move(arg);
    return Init_SystemState_task_run_id(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_task_pc
{
public:
  explicit Init_SystemState_task_pc(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_task_repeat task_pc(::rbpodo_msgs::msg::SystemState::_task_pc_type arg)
  {
    msg_.task_pc = std::move(arg);
    return Init_SystemState_task_repeat(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_jnt_temperature
{
public:
  explicit Init_SystemState_jnt_temperature(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_task_pc jnt_temperature(::rbpodo_msgs::msg::SystemState::_jnt_temperature_type arg)
  {
    msg_.jnt_temperature = std::move(arg);
    return Init_SystemState_task_pc(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_digital_out
{
public:
  explicit Init_SystemState_digital_out(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_jnt_temperature digital_out(::rbpodo_msgs::msg::SystemState::_digital_out_type arg)
  {
    msg_.digital_out = std::move(arg);
    return Init_SystemState_jnt_temperature(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_digital_in
{
public:
  explicit Init_SystemState_digital_in(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_digital_out digital_in(::rbpodo_msgs::msg::SystemState::_digital_in_type arg)
  {
    msg_.digital_in = std::move(arg);
    return Init_SystemState_digital_out(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_analog_out
{
public:
  explicit Init_SystemState_analog_out(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_digital_in analog_out(::rbpodo_msgs::msg::SystemState::_analog_out_type arg)
  {
    msg_.analog_out = std::move(arg);
    return Init_SystemState_digital_in(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_analog_in
{
public:
  explicit Init_SystemState_analog_in(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_analog_out analog_in(::rbpodo_msgs::msg::SystemState::_analog_in_type arg)
  {
    msg_.analog_in = std::move(arg);
    return Init_SystemState_analog_out(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_tcp_pos
{
public:
  explicit Init_SystemState_tcp_pos(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_analog_in tcp_pos(::rbpodo_msgs::msg::SystemState::_tcp_pos_type arg)
  {
    msg_.tcp_pos = std::move(arg);
    return Init_SystemState_analog_in(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_tcp_ref
{
public:
  explicit Init_SystemState_tcp_ref(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tcp_pos tcp_ref(::rbpodo_msgs::msg::SystemState::_tcp_ref_type arg)
  {
    msg_.tcp_ref = std::move(arg);
    return Init_SystemState_tcp_pos(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_jnt_cur
{
public:
  explicit Init_SystemState_jnt_cur(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_tcp_ref jnt_cur(::rbpodo_msgs::msg::SystemState::_jnt_cur_type arg)
  {
    msg_.jnt_cur = std::move(arg);
    return Init_SystemState_tcp_ref(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_jnt_ang
{
public:
  explicit Init_SystemState_jnt_ang(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_jnt_cur jnt_ang(::rbpodo_msgs::msg::SystemState::_jnt_ang_type arg)
  {
    msg_.jnt_ang = std::move(arg);
    return Init_SystemState_jnt_cur(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_jnt_ref
{
public:
  explicit Init_SystemState_jnt_ref(::rbpodo_msgs::msg::SystemState & msg)
  : msg_(msg)
  {}
  Init_SystemState_jnt_ang jnt_ref(::rbpodo_msgs::msg::SystemState::_jnt_ref_type arg)
  {
    msg_.jnt_ref = std::move(arg);
    return Init_SystemState_jnt_ang(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

class Init_SystemState_time
{
public:
  Init_SystemState_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SystemState_jnt_ref time(::rbpodo_msgs::msg::SystemState::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_SystemState_jnt_ref(msg_);
  }

private:
  ::rbpodo_msgs::msg::SystemState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rbpodo_msgs::msg::SystemState>()
{
  return rbpodo_msgs::msg::builder::Init_SystemState_time();
}

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__BUILDER_HPP_
