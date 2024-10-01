// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rbpodo_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__TRAITS_HPP_
#define RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rbpodo_msgs/msg/detail/system_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rbpodo_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SystemState & msg,
  std::ostream & out)
{
  out << "{";
  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << ", ";
  }

  // member: jnt_ref
  {
    if (msg.jnt_ref.size() == 0) {
      out << "jnt_ref: []";
    } else {
      out << "jnt_ref: [";
      size_t pending_items = msg.jnt_ref.size();
      for (auto item : msg.jnt_ref) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: jnt_ang
  {
    if (msg.jnt_ang.size() == 0) {
      out << "jnt_ang: []";
    } else {
      out << "jnt_ang: [";
      size_t pending_items = msg.jnt_ang.size();
      for (auto item : msg.jnt_ang) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: jnt_cur
  {
    if (msg.jnt_cur.size() == 0) {
      out << "jnt_cur: []";
    } else {
      out << "jnt_cur: [";
      size_t pending_items = msg.jnt_cur.size();
      for (auto item : msg.jnt_cur) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tcp_ref
  {
    if (msg.tcp_ref.size() == 0) {
      out << "tcp_ref: []";
    } else {
      out << "tcp_ref: [";
      size_t pending_items = msg.tcp_ref.size();
      for (auto item : msg.tcp_ref) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tcp_pos
  {
    if (msg.tcp_pos.size() == 0) {
      out << "tcp_pos: []";
    } else {
      out << "tcp_pos: [";
      size_t pending_items = msg.tcp_pos.size();
      for (auto item : msg.tcp_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: analog_in
  {
    if (msg.analog_in.size() == 0) {
      out << "analog_in: []";
    } else {
      out << "analog_in: [";
      size_t pending_items = msg.analog_in.size();
      for (auto item : msg.analog_in) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: analog_out
  {
    if (msg.analog_out.size() == 0) {
      out << "analog_out: []";
    } else {
      out << "analog_out: [";
      size_t pending_items = msg.analog_out.size();
      for (auto item : msg.analog_out) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: digital_in
  {
    if (msg.digital_in.size() == 0) {
      out << "digital_in: []";
    } else {
      out << "digital_in: [";
      size_t pending_items = msg.digital_in.size();
      for (auto item : msg.digital_in) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: digital_out
  {
    if (msg.digital_out.size() == 0) {
      out << "digital_out: []";
    } else {
      out << "digital_out: [";
      size_t pending_items = msg.digital_out.size();
      for (auto item : msg.digital_out) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: jnt_temperature
  {
    if (msg.jnt_temperature.size() == 0) {
      out << "jnt_temperature: []";
    } else {
      out << "jnt_temperature: [";
      size_t pending_items = msg.jnt_temperature.size();
      for (auto item : msg.jnt_temperature) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: task_pc
  {
    out << "task_pc: ";
    rosidl_generator_traits::value_to_yaml(msg.task_pc, out);
    out << ", ";
  }

  // member: task_repeat
  {
    out << "task_repeat: ";
    rosidl_generator_traits::value_to_yaml(msg.task_repeat, out);
    out << ", ";
  }

  // member: task_run_id
  {
    out << "task_run_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_run_id, out);
    out << ", ";
  }

  // member: task_run_num
  {
    out << "task_run_num: ";
    rosidl_generator_traits::value_to_yaml(msg.task_run_num, out);
    out << ", ";
  }

  // member: task_run_time
  {
    out << "task_run_time: ";
    rosidl_generator_traits::value_to_yaml(msg.task_run_time, out);
    out << ", ";
  }

  // member: task_state
  {
    out << "task_state: ";
    rosidl_generator_traits::value_to_yaml(msg.task_state, out);
    out << ", ";
  }

  // member: default_speed
  {
    out << "default_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.default_speed, out);
    out << ", ";
  }

  // member: robot_state
  {
    out << "robot_state: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_state, out);
    out << ", ";
  }

  // member: information_chunk_1
  {
    out << "information_chunk_1: ";
    rosidl_generator_traits::value_to_yaml(msg.information_chunk_1, out);
    out << ", ";
  }

  // member: jnt_info
  {
    if (msg.jnt_info.size() == 0) {
      out << "jnt_info: []";
    } else {
      out << "jnt_info: [";
      size_t pending_items = msg.jnt_info.size();
      for (auto item : msg.jnt_info) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: collision_detect_onoff
  {
    out << "collision_detect_onoff: ";
    rosidl_generator_traits::value_to_yaml(msg.collision_detect_onoff, out);
    out << ", ";
  }

  // member: is_freedrive_mode
  {
    out << "is_freedrive_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.is_freedrive_mode, out);
    out << ", ";
  }

  // member: real_vs_simulation_mode
  {
    out << "real_vs_simulation_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.real_vs_simulation_mode, out);
    out << ", ";
  }

  // member: init_state_info
  {
    out << "init_state_info: ";
    rosidl_generator_traits::value_to_yaml(msg.init_state_info, out);
    out << ", ";
  }

  // member: init_error
  {
    out << "init_error: ";
    rosidl_generator_traits::value_to_yaml(msg.init_error, out);
    out << ", ";
  }

  // member: tfb_analog_in
  {
    if (msg.tfb_analog_in.size() == 0) {
      out << "tfb_analog_in: []";
    } else {
      out << "tfb_analog_in: [";
      size_t pending_items = msg.tfb_analog_in.size();
      for (auto item : msg.tfb_analog_in) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tfb_digital_in
  {
    if (msg.tfb_digital_in.size() == 0) {
      out << "tfb_digital_in: []";
    } else {
      out << "tfb_digital_in: [";
      size_t pending_items = msg.tfb_digital_in.size();
      for (auto item : msg.tfb_digital_in) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tfb_digital_out
  {
    if (msg.tfb_digital_out.size() == 0) {
      out << "tfb_digital_out: []";
    } else {
      out << "tfb_digital_out: [";
      size_t pending_items = msg.tfb_digital_out.size();
      for (auto item : msg.tfb_digital_out) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tfb_voltage_out
  {
    out << "tfb_voltage_out: ";
    rosidl_generator_traits::value_to_yaml(msg.tfb_voltage_out, out);
    out << ", ";
  }

  // member: op_stat_collision_occur
  {
    out << "op_stat_collision_occur: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_collision_occur, out);
    out << ", ";
  }

  // member: op_stat_sos_flag
  {
    out << "op_stat_sos_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_sos_flag, out);
    out << ", ";
  }

  // member: op_stat_self_collision
  {
    out << "op_stat_self_collision: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_self_collision, out);
    out << ", ";
  }

  // member: op_stat_soft_estop_occur
  {
    out << "op_stat_soft_estop_occur: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_soft_estop_occur, out);
    out << ", ";
  }

  // member: op_stat_ems_flag
  {
    out << "op_stat_ems_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_ems_flag, out);
    out << ", ";
  }

  // member: information_chunk_2
  {
    out << "information_chunk_2: ";
    rosidl_generator_traits::value_to_yaml(msg.information_chunk_2, out);
    out << ", ";
  }

  // member: information_chunk_3
  {
    out << "information_chunk_3: ";
    rosidl_generator_traits::value_to_yaml(msg.information_chunk_3, out);
    out << ", ";
  }

  // member: inbox_trap_flag
  {
    if (msg.inbox_trap_flag.size() == 0) {
      out << "inbox_trap_flag: []";
    } else {
      out << "inbox_trap_flag: [";
      size_t pending_items = msg.inbox_trap_flag.size();
      for (auto item : msg.inbox_trap_flag) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: inbox_check_mode
  {
    if (msg.inbox_check_mode.size() == 0) {
      out << "inbox_check_mode: []";
    } else {
      out << "inbox_check_mode: [";
      size_t pending_items = msg.inbox_check_mode.size();
      for (auto item : msg.inbox_check_mode) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: eft
  {
    if (msg.eft.size() == 0) {
      out << "eft: []";
    } else {
      out << "eft: [";
      size_t pending_items = msg.eft.size();
      for (auto item : msg.eft) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: information_chunk_4
  {
    out << "information_chunk_4: ";
    rosidl_generator_traits::value_to_yaml(msg.information_chunk_4, out);
    out << ", ";
  }

  // member: extend_io1_analog_in
  {
    if (msg.extend_io1_analog_in.size() == 0) {
      out << "extend_io1_analog_in: []";
    } else {
      out << "extend_io1_analog_in: [";
      size_t pending_items = msg.extend_io1_analog_in.size();
      for (auto item : msg.extend_io1_analog_in) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: extend_io1_analog_out
  {
    if (msg.extend_io1_analog_out.size() == 0) {
      out << "extend_io1_analog_out: []";
    } else {
      out << "extend_io1_analog_out: [";
      size_t pending_items = msg.extend_io1_analog_out.size();
      for (auto item : msg.extend_io1_analog_out) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: extend_io1_digital_info
  {
    out << "extend_io1_digital_info: ";
    rosidl_generator_traits::value_to_yaml(msg.extend_io1_digital_info, out);
    out << ", ";
  }

  // member: aa_joint_ref
  {
    if (msg.aa_joint_ref.size() == 0) {
      out << "aa_joint_ref: []";
    } else {
      out << "aa_joint_ref: [";
      size_t pending_items = msg.aa_joint_ref.size();
      for (auto item : msg.aa_joint_ref) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: safety_board_stat_info
  {
    out << "safety_board_stat_info: ";
    rosidl_generator_traits::value_to_yaml(msg.safety_board_stat_info, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SystemState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }

  // member: jnt_ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jnt_ref.size() == 0) {
      out << "jnt_ref: []\n";
    } else {
      out << "jnt_ref:\n";
      for (auto item : msg.jnt_ref) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: jnt_ang
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jnt_ang.size() == 0) {
      out << "jnt_ang: []\n";
    } else {
      out << "jnt_ang:\n";
      for (auto item : msg.jnt_ang) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: jnt_cur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jnt_cur.size() == 0) {
      out << "jnt_cur: []\n";
    } else {
      out << "jnt_cur:\n";
      for (auto item : msg.jnt_cur) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tcp_ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tcp_ref.size() == 0) {
      out << "tcp_ref: []\n";
    } else {
      out << "tcp_ref:\n";
      for (auto item : msg.tcp_ref) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tcp_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tcp_pos.size() == 0) {
      out << "tcp_pos: []\n";
    } else {
      out << "tcp_pos:\n";
      for (auto item : msg.tcp_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: analog_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.analog_in.size() == 0) {
      out << "analog_in: []\n";
    } else {
      out << "analog_in:\n";
      for (auto item : msg.analog_in) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: analog_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.analog_out.size() == 0) {
      out << "analog_out: []\n";
    } else {
      out << "analog_out:\n";
      for (auto item : msg.analog_out) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: digital_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.digital_in.size() == 0) {
      out << "digital_in: []\n";
    } else {
      out << "digital_in:\n";
      for (auto item : msg.digital_in) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: digital_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.digital_out.size() == 0) {
      out << "digital_out: []\n";
    } else {
      out << "digital_out:\n";
      for (auto item : msg.digital_out) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: jnt_temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jnt_temperature.size() == 0) {
      out << "jnt_temperature: []\n";
    } else {
      out << "jnt_temperature:\n";
      for (auto item : msg.jnt_temperature) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: task_pc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_pc: ";
    rosidl_generator_traits::value_to_yaml(msg.task_pc, out);
    out << "\n";
  }

  // member: task_repeat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_repeat: ";
    rosidl_generator_traits::value_to_yaml(msg.task_repeat, out);
    out << "\n";
  }

  // member: task_run_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_run_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_run_id, out);
    out << "\n";
  }

  // member: task_run_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_run_num: ";
    rosidl_generator_traits::value_to_yaml(msg.task_run_num, out);
    out << "\n";
  }

  // member: task_run_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_run_time: ";
    rosidl_generator_traits::value_to_yaml(msg.task_run_time, out);
    out << "\n";
  }

  // member: task_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_state: ";
    rosidl_generator_traits::value_to_yaml(msg.task_state, out);
    out << "\n";
  }

  // member: default_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "default_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.default_speed, out);
    out << "\n";
  }

  // member: robot_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_state: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_state, out);
    out << "\n";
  }

  // member: information_chunk_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "information_chunk_1: ";
    rosidl_generator_traits::value_to_yaml(msg.information_chunk_1, out);
    out << "\n";
  }

  // member: jnt_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jnt_info.size() == 0) {
      out << "jnt_info: []\n";
    } else {
      out << "jnt_info:\n";
      for (auto item : msg.jnt_info) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: collision_detect_onoff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "collision_detect_onoff: ";
    rosidl_generator_traits::value_to_yaml(msg.collision_detect_onoff, out);
    out << "\n";
  }

  // member: is_freedrive_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_freedrive_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.is_freedrive_mode, out);
    out << "\n";
  }

  // member: real_vs_simulation_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "real_vs_simulation_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.real_vs_simulation_mode, out);
    out << "\n";
  }

  // member: init_state_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "init_state_info: ";
    rosidl_generator_traits::value_to_yaml(msg.init_state_info, out);
    out << "\n";
  }

  // member: init_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "init_error: ";
    rosidl_generator_traits::value_to_yaml(msg.init_error, out);
    out << "\n";
  }

  // member: tfb_analog_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tfb_analog_in.size() == 0) {
      out << "tfb_analog_in: []\n";
    } else {
      out << "tfb_analog_in:\n";
      for (auto item : msg.tfb_analog_in) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tfb_digital_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tfb_digital_in.size() == 0) {
      out << "tfb_digital_in: []\n";
    } else {
      out << "tfb_digital_in:\n";
      for (auto item : msg.tfb_digital_in) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tfb_digital_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tfb_digital_out.size() == 0) {
      out << "tfb_digital_out: []\n";
    } else {
      out << "tfb_digital_out:\n";
      for (auto item : msg.tfb_digital_out) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tfb_voltage_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tfb_voltage_out: ";
    rosidl_generator_traits::value_to_yaml(msg.tfb_voltage_out, out);
    out << "\n";
  }

  // member: op_stat_collision_occur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "op_stat_collision_occur: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_collision_occur, out);
    out << "\n";
  }

  // member: op_stat_sos_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "op_stat_sos_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_sos_flag, out);
    out << "\n";
  }

  // member: op_stat_self_collision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "op_stat_self_collision: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_self_collision, out);
    out << "\n";
  }

  // member: op_stat_soft_estop_occur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "op_stat_soft_estop_occur: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_soft_estop_occur, out);
    out << "\n";
  }

  // member: op_stat_ems_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "op_stat_ems_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.op_stat_ems_flag, out);
    out << "\n";
  }

  // member: information_chunk_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "information_chunk_2: ";
    rosidl_generator_traits::value_to_yaml(msg.information_chunk_2, out);
    out << "\n";
  }

  // member: information_chunk_3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "information_chunk_3: ";
    rosidl_generator_traits::value_to_yaml(msg.information_chunk_3, out);
    out << "\n";
  }

  // member: inbox_trap_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.inbox_trap_flag.size() == 0) {
      out << "inbox_trap_flag: []\n";
    } else {
      out << "inbox_trap_flag:\n";
      for (auto item : msg.inbox_trap_flag) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: inbox_check_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.inbox_check_mode.size() == 0) {
      out << "inbox_check_mode: []\n";
    } else {
      out << "inbox_check_mode:\n";
      for (auto item : msg.inbox_check_mode) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: eft
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.eft.size() == 0) {
      out << "eft: []\n";
    } else {
      out << "eft:\n";
      for (auto item : msg.eft) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: information_chunk_4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "information_chunk_4: ";
    rosidl_generator_traits::value_to_yaml(msg.information_chunk_4, out);
    out << "\n";
  }

  // member: extend_io1_analog_in
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.extend_io1_analog_in.size() == 0) {
      out << "extend_io1_analog_in: []\n";
    } else {
      out << "extend_io1_analog_in:\n";
      for (auto item : msg.extend_io1_analog_in) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: extend_io1_analog_out
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.extend_io1_analog_out.size() == 0) {
      out << "extend_io1_analog_out: []\n";
    } else {
      out << "extend_io1_analog_out:\n";
      for (auto item : msg.extend_io1_analog_out) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: extend_io1_digital_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "extend_io1_digital_info: ";
    rosidl_generator_traits::value_to_yaml(msg.extend_io1_digital_info, out);
    out << "\n";
  }

  // member: aa_joint_ref
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.aa_joint_ref.size() == 0) {
      out << "aa_joint_ref: []\n";
    } else {
      out << "aa_joint_ref:\n";
      for (auto item : msg.aa_joint_ref) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: safety_board_stat_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "safety_board_stat_info: ";
    rosidl_generator_traits::value_to_yaml(msg.safety_board_stat_info, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SystemState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rbpodo_msgs

namespace rosidl_generator_traits
{

[[deprecated("use rbpodo_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rbpodo_msgs::msg::SystemState & msg,
  std::ostream & out, size_t indentation = 0)
{
  rbpodo_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rbpodo_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const rbpodo_msgs::msg::SystemState & msg)
{
  return rbpodo_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rbpodo_msgs::msg::SystemState>()
{
  return "rbpodo_msgs::msg::SystemState";
}

template<>
inline const char * name<rbpodo_msgs::msg::SystemState>()
{
  return "rbpodo_msgs/msg/SystemState";
}

template<>
struct has_fixed_size<rbpodo_msgs::msg::SystemState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<rbpodo_msgs::msg::SystemState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<rbpodo_msgs::msg::SystemState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RBPODO_MSGS__MSG__DETAIL__SYSTEM_STATE__TRAITS_HPP_
