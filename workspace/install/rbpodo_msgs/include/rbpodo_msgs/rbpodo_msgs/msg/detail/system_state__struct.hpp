// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rbpodo_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_HPP_
#define RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rbpodo_msgs__msg__SystemState __attribute__((deprecated))
#else
# define DEPRECATED__rbpodo_msgs__msg__SystemState __declspec(deprecated)
#endif

namespace rbpodo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SystemState_
{
  using Type = SystemState_<ContainerAllocator>;

  explicit SystemState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0f;
      std::fill<typename std::array<float, 6>::iterator, float>(this->jnt_ref.begin(), this->jnt_ref.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->jnt_ang.begin(), this->jnt_ang.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->jnt_cur.begin(), this->jnt_cur.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->tcp_ref.begin(), this->tcp_ref.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->tcp_pos.begin(), this->tcp_pos.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->analog_in.begin(), this->analog_in.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->analog_out.begin(), this->analog_out.end(), 0.0f);
      std::fill<typename std::array<bool, 16>::iterator, bool>(this->digital_in.begin(), this->digital_in.end(), false);
      std::fill<typename std::array<bool, 16>::iterator, bool>(this->digital_out.begin(), this->digital_out.end(), false);
      std::fill<typename std::array<float, 6>::iterator, float>(this->jnt_temperature.begin(), this->jnt_temperature.end(), 0.0f);
      this->task_pc = 0l;
      this->task_repeat = 0l;
      this->task_run_id = 0l;
      this->task_run_num = 0l;
      this->task_run_time = 0l;
      this->task_state = 0l;
      this->default_speed = 0.0f;
      this->robot_state = 0l;
      this->information_chunk_1 = 0l;
      std::fill<typename std::array<int32_t, 6>::iterator, int32_t>(this->jnt_info.begin(), this->jnt_info.end(), 0l);
      this->collision_detect_onoff = false;
      this->is_freedrive_mode = false;
      this->real_vs_simulation_mode = false;
      this->init_state_info = 0;
      this->init_error = 0l;
      std::fill<typename std::array<float, 2>::iterator, float>(this->tfb_analog_in.begin(), this->tfb_analog_in.end(), 0.0f);
      std::fill<typename std::array<bool, 2>::iterator, bool>(this->tfb_digital_in.begin(), this->tfb_digital_in.end(), false);
      std::fill<typename std::array<bool, 2>::iterator, bool>(this->tfb_digital_out.begin(), this->tfb_digital_out.end(), false);
      this->tfb_voltage_out = 0.0f;
      this->op_stat_collision_occur = false;
      this->op_stat_sos_flag = 0;
      this->op_stat_self_collision = false;
      this->op_stat_soft_estop_occur = false;
      this->op_stat_ems_flag = 0;
      this->information_chunk_2 = 0l;
      this->information_chunk_3 = 0l;
      std::fill<typename std::array<bool, 2>::iterator, bool>(this->inbox_trap_flag.begin(), this->inbox_trap_flag.end(), false);
      std::fill<typename std::array<int8_t, 2>::iterator, int8_t>(this->inbox_check_mode.begin(), this->inbox_check_mode.end(), 0);
      std::fill<typename std::array<float, 6>::iterator, float>(this->eft.begin(), this->eft.end(), 0.0f);
      this->information_chunk_4 = 0l;
      std::fill<typename std::array<float, 4>::iterator, float>(this->extend_io1_analog_in.begin(), this->extend_io1_analog_in.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->extend_io1_analog_out.begin(), this->extend_io1_analog_out.end(), 0.0f);
      this->extend_io1_digital_info = 0ul;
      std::fill<typename std::array<float, 6>::iterator, float>(this->aa_joint_ref.begin(), this->aa_joint_ref.end(), 0.0f);
      this->safety_board_stat_info = 0ul;
    }
  }

  explicit SystemState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : jnt_ref(_alloc),
    jnt_ang(_alloc),
    jnt_cur(_alloc),
    tcp_ref(_alloc),
    tcp_pos(_alloc),
    analog_in(_alloc),
    analog_out(_alloc),
    digital_in(_alloc),
    digital_out(_alloc),
    jnt_temperature(_alloc),
    jnt_info(_alloc),
    tfb_analog_in(_alloc),
    tfb_digital_in(_alloc),
    tfb_digital_out(_alloc),
    inbox_trap_flag(_alloc),
    inbox_check_mode(_alloc),
    eft(_alloc),
    extend_io1_analog_in(_alloc),
    extend_io1_analog_out(_alloc),
    aa_joint_ref(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time = 0.0f;
      std::fill<typename std::array<float, 6>::iterator, float>(this->jnt_ref.begin(), this->jnt_ref.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->jnt_ang.begin(), this->jnt_ang.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->jnt_cur.begin(), this->jnt_cur.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->tcp_ref.begin(), this->tcp_ref.end(), 0.0f);
      std::fill<typename std::array<float, 6>::iterator, float>(this->tcp_pos.begin(), this->tcp_pos.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->analog_in.begin(), this->analog_in.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->analog_out.begin(), this->analog_out.end(), 0.0f);
      std::fill<typename std::array<bool, 16>::iterator, bool>(this->digital_in.begin(), this->digital_in.end(), false);
      std::fill<typename std::array<bool, 16>::iterator, bool>(this->digital_out.begin(), this->digital_out.end(), false);
      std::fill<typename std::array<float, 6>::iterator, float>(this->jnt_temperature.begin(), this->jnt_temperature.end(), 0.0f);
      this->task_pc = 0l;
      this->task_repeat = 0l;
      this->task_run_id = 0l;
      this->task_run_num = 0l;
      this->task_run_time = 0l;
      this->task_state = 0l;
      this->default_speed = 0.0f;
      this->robot_state = 0l;
      this->information_chunk_1 = 0l;
      std::fill<typename std::array<int32_t, 6>::iterator, int32_t>(this->jnt_info.begin(), this->jnt_info.end(), 0l);
      this->collision_detect_onoff = false;
      this->is_freedrive_mode = false;
      this->real_vs_simulation_mode = false;
      this->init_state_info = 0;
      this->init_error = 0l;
      std::fill<typename std::array<float, 2>::iterator, float>(this->tfb_analog_in.begin(), this->tfb_analog_in.end(), 0.0f);
      std::fill<typename std::array<bool, 2>::iterator, bool>(this->tfb_digital_in.begin(), this->tfb_digital_in.end(), false);
      std::fill<typename std::array<bool, 2>::iterator, bool>(this->tfb_digital_out.begin(), this->tfb_digital_out.end(), false);
      this->tfb_voltage_out = 0.0f;
      this->op_stat_collision_occur = false;
      this->op_stat_sos_flag = 0;
      this->op_stat_self_collision = false;
      this->op_stat_soft_estop_occur = false;
      this->op_stat_ems_flag = 0;
      this->information_chunk_2 = 0l;
      this->information_chunk_3 = 0l;
      std::fill<typename std::array<bool, 2>::iterator, bool>(this->inbox_trap_flag.begin(), this->inbox_trap_flag.end(), false);
      std::fill<typename std::array<int8_t, 2>::iterator, int8_t>(this->inbox_check_mode.begin(), this->inbox_check_mode.end(), 0);
      std::fill<typename std::array<float, 6>::iterator, float>(this->eft.begin(), this->eft.end(), 0.0f);
      this->information_chunk_4 = 0l;
      std::fill<typename std::array<float, 4>::iterator, float>(this->extend_io1_analog_in.begin(), this->extend_io1_analog_in.end(), 0.0f);
      std::fill<typename std::array<float, 4>::iterator, float>(this->extend_io1_analog_out.begin(), this->extend_io1_analog_out.end(), 0.0f);
      this->extend_io1_digital_info = 0ul;
      std::fill<typename std::array<float, 6>::iterator, float>(this->aa_joint_ref.begin(), this->aa_joint_ref.end(), 0.0f);
      this->safety_board_stat_info = 0ul;
    }
  }

  // field types and members
  using _time_type =
    float;
  _time_type time;
  using _jnt_ref_type =
    std::array<float, 6>;
  _jnt_ref_type jnt_ref;
  using _jnt_ang_type =
    std::array<float, 6>;
  _jnt_ang_type jnt_ang;
  using _jnt_cur_type =
    std::array<float, 6>;
  _jnt_cur_type jnt_cur;
  using _tcp_ref_type =
    std::array<float, 6>;
  _tcp_ref_type tcp_ref;
  using _tcp_pos_type =
    std::array<float, 6>;
  _tcp_pos_type tcp_pos;
  using _analog_in_type =
    std::array<float, 4>;
  _analog_in_type analog_in;
  using _analog_out_type =
    std::array<float, 4>;
  _analog_out_type analog_out;
  using _digital_in_type =
    std::array<bool, 16>;
  _digital_in_type digital_in;
  using _digital_out_type =
    std::array<bool, 16>;
  _digital_out_type digital_out;
  using _jnt_temperature_type =
    std::array<float, 6>;
  _jnt_temperature_type jnt_temperature;
  using _task_pc_type =
    int32_t;
  _task_pc_type task_pc;
  using _task_repeat_type =
    int32_t;
  _task_repeat_type task_repeat;
  using _task_run_id_type =
    int32_t;
  _task_run_id_type task_run_id;
  using _task_run_num_type =
    int32_t;
  _task_run_num_type task_run_num;
  using _task_run_time_type =
    int32_t;
  _task_run_time_type task_run_time;
  using _task_state_type =
    int32_t;
  _task_state_type task_state;
  using _default_speed_type =
    float;
  _default_speed_type default_speed;
  using _robot_state_type =
    int32_t;
  _robot_state_type robot_state;
  using _information_chunk_1_type =
    int32_t;
  _information_chunk_1_type information_chunk_1;
  using _jnt_info_type =
    std::array<int32_t, 6>;
  _jnt_info_type jnt_info;
  using _collision_detect_onoff_type =
    bool;
  _collision_detect_onoff_type collision_detect_onoff;
  using _is_freedrive_mode_type =
    bool;
  _is_freedrive_mode_type is_freedrive_mode;
  using _real_vs_simulation_mode_type =
    bool;
  _real_vs_simulation_mode_type real_vs_simulation_mode;
  using _init_state_info_type =
    int8_t;
  _init_state_info_type init_state_info;
  using _init_error_type =
    int32_t;
  _init_error_type init_error;
  using _tfb_analog_in_type =
    std::array<float, 2>;
  _tfb_analog_in_type tfb_analog_in;
  using _tfb_digital_in_type =
    std::array<bool, 2>;
  _tfb_digital_in_type tfb_digital_in;
  using _tfb_digital_out_type =
    std::array<bool, 2>;
  _tfb_digital_out_type tfb_digital_out;
  using _tfb_voltage_out_type =
    float;
  _tfb_voltage_out_type tfb_voltage_out;
  using _op_stat_collision_occur_type =
    bool;
  _op_stat_collision_occur_type op_stat_collision_occur;
  using _op_stat_sos_flag_type =
    int8_t;
  _op_stat_sos_flag_type op_stat_sos_flag;
  using _op_stat_self_collision_type =
    bool;
  _op_stat_self_collision_type op_stat_self_collision;
  using _op_stat_soft_estop_occur_type =
    bool;
  _op_stat_soft_estop_occur_type op_stat_soft_estop_occur;
  using _op_stat_ems_flag_type =
    int8_t;
  _op_stat_ems_flag_type op_stat_ems_flag;
  using _information_chunk_2_type =
    int32_t;
  _information_chunk_2_type information_chunk_2;
  using _information_chunk_3_type =
    int32_t;
  _information_chunk_3_type information_chunk_3;
  using _inbox_trap_flag_type =
    std::array<bool, 2>;
  _inbox_trap_flag_type inbox_trap_flag;
  using _inbox_check_mode_type =
    std::array<int8_t, 2>;
  _inbox_check_mode_type inbox_check_mode;
  using _eft_type =
    std::array<float, 6>;
  _eft_type eft;
  using _information_chunk_4_type =
    int32_t;
  _information_chunk_4_type information_chunk_4;
  using _extend_io1_analog_in_type =
    std::array<float, 4>;
  _extend_io1_analog_in_type extend_io1_analog_in;
  using _extend_io1_analog_out_type =
    std::array<float, 4>;
  _extend_io1_analog_out_type extend_io1_analog_out;
  using _extend_io1_digital_info_type =
    uint32_t;
  _extend_io1_digital_info_type extend_io1_digital_info;
  using _aa_joint_ref_type =
    std::array<float, 6>;
  _aa_joint_ref_type aa_joint_ref;
  using _safety_board_stat_info_type =
    uint32_t;
  _safety_board_stat_info_type safety_board_stat_info;

  // setters for named parameter idiom
  Type & set__time(
    const float & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__jnt_ref(
    const std::array<float, 6> & _arg)
  {
    this->jnt_ref = _arg;
    return *this;
  }
  Type & set__jnt_ang(
    const std::array<float, 6> & _arg)
  {
    this->jnt_ang = _arg;
    return *this;
  }
  Type & set__jnt_cur(
    const std::array<float, 6> & _arg)
  {
    this->jnt_cur = _arg;
    return *this;
  }
  Type & set__tcp_ref(
    const std::array<float, 6> & _arg)
  {
    this->tcp_ref = _arg;
    return *this;
  }
  Type & set__tcp_pos(
    const std::array<float, 6> & _arg)
  {
    this->tcp_pos = _arg;
    return *this;
  }
  Type & set__analog_in(
    const std::array<float, 4> & _arg)
  {
    this->analog_in = _arg;
    return *this;
  }
  Type & set__analog_out(
    const std::array<float, 4> & _arg)
  {
    this->analog_out = _arg;
    return *this;
  }
  Type & set__digital_in(
    const std::array<bool, 16> & _arg)
  {
    this->digital_in = _arg;
    return *this;
  }
  Type & set__digital_out(
    const std::array<bool, 16> & _arg)
  {
    this->digital_out = _arg;
    return *this;
  }
  Type & set__jnt_temperature(
    const std::array<float, 6> & _arg)
  {
    this->jnt_temperature = _arg;
    return *this;
  }
  Type & set__task_pc(
    const int32_t & _arg)
  {
    this->task_pc = _arg;
    return *this;
  }
  Type & set__task_repeat(
    const int32_t & _arg)
  {
    this->task_repeat = _arg;
    return *this;
  }
  Type & set__task_run_id(
    const int32_t & _arg)
  {
    this->task_run_id = _arg;
    return *this;
  }
  Type & set__task_run_num(
    const int32_t & _arg)
  {
    this->task_run_num = _arg;
    return *this;
  }
  Type & set__task_run_time(
    const int32_t & _arg)
  {
    this->task_run_time = _arg;
    return *this;
  }
  Type & set__task_state(
    const int32_t & _arg)
  {
    this->task_state = _arg;
    return *this;
  }
  Type & set__default_speed(
    const float & _arg)
  {
    this->default_speed = _arg;
    return *this;
  }
  Type & set__robot_state(
    const int32_t & _arg)
  {
    this->robot_state = _arg;
    return *this;
  }
  Type & set__information_chunk_1(
    const int32_t & _arg)
  {
    this->information_chunk_1 = _arg;
    return *this;
  }
  Type & set__jnt_info(
    const std::array<int32_t, 6> & _arg)
  {
    this->jnt_info = _arg;
    return *this;
  }
  Type & set__collision_detect_onoff(
    const bool & _arg)
  {
    this->collision_detect_onoff = _arg;
    return *this;
  }
  Type & set__is_freedrive_mode(
    const bool & _arg)
  {
    this->is_freedrive_mode = _arg;
    return *this;
  }
  Type & set__real_vs_simulation_mode(
    const bool & _arg)
  {
    this->real_vs_simulation_mode = _arg;
    return *this;
  }
  Type & set__init_state_info(
    const int8_t & _arg)
  {
    this->init_state_info = _arg;
    return *this;
  }
  Type & set__init_error(
    const int32_t & _arg)
  {
    this->init_error = _arg;
    return *this;
  }
  Type & set__tfb_analog_in(
    const std::array<float, 2> & _arg)
  {
    this->tfb_analog_in = _arg;
    return *this;
  }
  Type & set__tfb_digital_in(
    const std::array<bool, 2> & _arg)
  {
    this->tfb_digital_in = _arg;
    return *this;
  }
  Type & set__tfb_digital_out(
    const std::array<bool, 2> & _arg)
  {
    this->tfb_digital_out = _arg;
    return *this;
  }
  Type & set__tfb_voltage_out(
    const float & _arg)
  {
    this->tfb_voltage_out = _arg;
    return *this;
  }
  Type & set__op_stat_collision_occur(
    const bool & _arg)
  {
    this->op_stat_collision_occur = _arg;
    return *this;
  }
  Type & set__op_stat_sos_flag(
    const int8_t & _arg)
  {
    this->op_stat_sos_flag = _arg;
    return *this;
  }
  Type & set__op_stat_self_collision(
    const bool & _arg)
  {
    this->op_stat_self_collision = _arg;
    return *this;
  }
  Type & set__op_stat_soft_estop_occur(
    const bool & _arg)
  {
    this->op_stat_soft_estop_occur = _arg;
    return *this;
  }
  Type & set__op_stat_ems_flag(
    const int8_t & _arg)
  {
    this->op_stat_ems_flag = _arg;
    return *this;
  }
  Type & set__information_chunk_2(
    const int32_t & _arg)
  {
    this->information_chunk_2 = _arg;
    return *this;
  }
  Type & set__information_chunk_3(
    const int32_t & _arg)
  {
    this->information_chunk_3 = _arg;
    return *this;
  }
  Type & set__inbox_trap_flag(
    const std::array<bool, 2> & _arg)
  {
    this->inbox_trap_flag = _arg;
    return *this;
  }
  Type & set__inbox_check_mode(
    const std::array<int8_t, 2> & _arg)
  {
    this->inbox_check_mode = _arg;
    return *this;
  }
  Type & set__eft(
    const std::array<float, 6> & _arg)
  {
    this->eft = _arg;
    return *this;
  }
  Type & set__information_chunk_4(
    const int32_t & _arg)
  {
    this->information_chunk_4 = _arg;
    return *this;
  }
  Type & set__extend_io1_analog_in(
    const std::array<float, 4> & _arg)
  {
    this->extend_io1_analog_in = _arg;
    return *this;
  }
  Type & set__extend_io1_analog_out(
    const std::array<float, 4> & _arg)
  {
    this->extend_io1_analog_out = _arg;
    return *this;
  }
  Type & set__extend_io1_digital_info(
    const uint32_t & _arg)
  {
    this->extend_io1_digital_info = _arg;
    return *this;
  }
  Type & set__aa_joint_ref(
    const std::array<float, 6> & _arg)
  {
    this->aa_joint_ref = _arg;
    return *this;
  }
  Type & set__safety_board_stat_info(
    const uint32_t & _arg)
  {
    this->safety_board_stat_info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rbpodo_msgs::msg::SystemState_<ContainerAllocator> *;
  using ConstRawPtr =
    const rbpodo_msgs::msg::SystemState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rbpodo_msgs::msg::SystemState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rbpodo_msgs::msg::SystemState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::msg::SystemState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::msg::SystemState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rbpodo_msgs::msg::SystemState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rbpodo_msgs::msg::SystemState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rbpodo_msgs::msg::SystemState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rbpodo_msgs::msg::SystemState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rbpodo_msgs__msg__SystemState
    std::shared_ptr<rbpodo_msgs::msg::SystemState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rbpodo_msgs__msg__SystemState
    std::shared_ptr<rbpodo_msgs::msg::SystemState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SystemState_ & other) const
  {
    if (this->time != other.time) {
      return false;
    }
    if (this->jnt_ref != other.jnt_ref) {
      return false;
    }
    if (this->jnt_ang != other.jnt_ang) {
      return false;
    }
    if (this->jnt_cur != other.jnt_cur) {
      return false;
    }
    if (this->tcp_ref != other.tcp_ref) {
      return false;
    }
    if (this->tcp_pos != other.tcp_pos) {
      return false;
    }
    if (this->analog_in != other.analog_in) {
      return false;
    }
    if (this->analog_out != other.analog_out) {
      return false;
    }
    if (this->digital_in != other.digital_in) {
      return false;
    }
    if (this->digital_out != other.digital_out) {
      return false;
    }
    if (this->jnt_temperature != other.jnt_temperature) {
      return false;
    }
    if (this->task_pc != other.task_pc) {
      return false;
    }
    if (this->task_repeat != other.task_repeat) {
      return false;
    }
    if (this->task_run_id != other.task_run_id) {
      return false;
    }
    if (this->task_run_num != other.task_run_num) {
      return false;
    }
    if (this->task_run_time != other.task_run_time) {
      return false;
    }
    if (this->task_state != other.task_state) {
      return false;
    }
    if (this->default_speed != other.default_speed) {
      return false;
    }
    if (this->robot_state != other.robot_state) {
      return false;
    }
    if (this->information_chunk_1 != other.information_chunk_1) {
      return false;
    }
    if (this->jnt_info != other.jnt_info) {
      return false;
    }
    if (this->collision_detect_onoff != other.collision_detect_onoff) {
      return false;
    }
    if (this->is_freedrive_mode != other.is_freedrive_mode) {
      return false;
    }
    if (this->real_vs_simulation_mode != other.real_vs_simulation_mode) {
      return false;
    }
    if (this->init_state_info != other.init_state_info) {
      return false;
    }
    if (this->init_error != other.init_error) {
      return false;
    }
    if (this->tfb_analog_in != other.tfb_analog_in) {
      return false;
    }
    if (this->tfb_digital_in != other.tfb_digital_in) {
      return false;
    }
    if (this->tfb_digital_out != other.tfb_digital_out) {
      return false;
    }
    if (this->tfb_voltage_out != other.tfb_voltage_out) {
      return false;
    }
    if (this->op_stat_collision_occur != other.op_stat_collision_occur) {
      return false;
    }
    if (this->op_stat_sos_flag != other.op_stat_sos_flag) {
      return false;
    }
    if (this->op_stat_self_collision != other.op_stat_self_collision) {
      return false;
    }
    if (this->op_stat_soft_estop_occur != other.op_stat_soft_estop_occur) {
      return false;
    }
    if (this->op_stat_ems_flag != other.op_stat_ems_flag) {
      return false;
    }
    if (this->information_chunk_2 != other.information_chunk_2) {
      return false;
    }
    if (this->information_chunk_3 != other.information_chunk_3) {
      return false;
    }
    if (this->inbox_trap_flag != other.inbox_trap_flag) {
      return false;
    }
    if (this->inbox_check_mode != other.inbox_check_mode) {
      return false;
    }
    if (this->eft != other.eft) {
      return false;
    }
    if (this->information_chunk_4 != other.information_chunk_4) {
      return false;
    }
    if (this->extend_io1_analog_in != other.extend_io1_analog_in) {
      return false;
    }
    if (this->extend_io1_analog_out != other.extend_io1_analog_out) {
      return false;
    }
    if (this->extend_io1_digital_info != other.extend_io1_digital_info) {
      return false;
    }
    if (this->aa_joint_ref != other.aa_joint_ref) {
      return false;
    }
    if (this->safety_board_stat_info != other.safety_board_stat_info) {
      return false;
    }
    return true;
  }
  bool operator!=(const SystemState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SystemState_

// alias to use template instance with default allocator
using SystemState =
  rbpodo_msgs::msg::SystemState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rbpodo_msgs

#endif  // RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_HPP_
