// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rbpodo_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rbpodo_msgs/msg/detail/system_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rbpodo_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SystemState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rbpodo_msgs::msg::SystemState(_init);
}

void SystemState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rbpodo_msgs::msg::SystemState *>(message_memory);
  typed_message->~SystemState();
}

size_t size_function__SystemState__jnt_ref(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__jnt_ref(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__jnt_ref(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__jnt_ref(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__jnt_ref(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__jnt_ref(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__jnt_ref(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__jnt_ang(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__jnt_ang(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__jnt_ang(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__jnt_ang(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__jnt_ang(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__jnt_ang(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__jnt_ang(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__jnt_cur(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__jnt_cur(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__jnt_cur(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__jnt_cur(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__jnt_cur(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__jnt_cur(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__jnt_cur(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__tcp_ref(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__tcp_ref(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tcp_ref(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__tcp_ref(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__tcp_ref(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__tcp_ref(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__tcp_ref(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__tcp_pos(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__tcp_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tcp_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__tcp_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__tcp_pos(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__tcp_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__tcp_pos(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__analog_in(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__SystemState__analog_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__analog_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__analog_in(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__analog_in(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__analog_in(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__analog_in(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__analog_out(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__SystemState__analog_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__analog_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__analog_out(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__analog_out(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__analog_out(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__analog_out(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__digital_in(const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * get_const_function__SystemState__digital_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 16> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__digital_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 16> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__digital_in(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__SystemState__digital_in(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__SystemState__digital_in(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__SystemState__digital_in(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__digital_out(const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * get_const_function__SystemState__digital_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 16> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__digital_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 16> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__digital_out(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__SystemState__digital_out(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__SystemState__digital_out(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__SystemState__digital_out(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__jnt_temperature(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__jnt_temperature(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__jnt_temperature(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__jnt_temperature(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__jnt_temperature(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__jnt_temperature(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__jnt_temperature(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__jnt_info(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__jnt_info(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int32_t, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__jnt_info(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int32_t, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__jnt_info(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int32_t *>(
    get_const_function__SystemState__jnt_info(untyped_member, index));
  auto & value = *reinterpret_cast<int32_t *>(untyped_value);
  value = item;
}

void assign_function__SystemState__jnt_info(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int32_t *>(
    get_function__SystemState__jnt_info(untyped_member, index));
  const auto & value = *reinterpret_cast<const int32_t *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__tfb_analog_in(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__tfb_analog_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tfb_analog_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__tfb_analog_in(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__tfb_analog_in(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__tfb_analog_in(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__tfb_analog_in(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__tfb_digital_in(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__tfb_digital_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tfb_digital_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__tfb_digital_in(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__SystemState__tfb_digital_in(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__SystemState__tfb_digital_in(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__SystemState__tfb_digital_in(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__tfb_digital_out(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__tfb_digital_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__tfb_digital_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__tfb_digital_out(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__SystemState__tfb_digital_out(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__SystemState__tfb_digital_out(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__SystemState__tfb_digital_out(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__inbox_trap_flag(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__inbox_trap_flag(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<bool, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__inbox_trap_flag(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<bool, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__inbox_trap_flag(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const bool *>(
    get_const_function__SystemState__inbox_trap_flag(untyped_member, index));
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = item;
}

void assign_function__SystemState__inbox_trap_flag(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<bool *>(
    get_function__SystemState__inbox_trap_flag(untyped_member, index));
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__inbox_check_mode(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__SystemState__inbox_check_mode(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__inbox_check_mode(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__inbox_check_mode(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int8_t *>(
    get_const_function__SystemState__inbox_check_mode(untyped_member, index));
  auto & value = *reinterpret_cast<int8_t *>(untyped_value);
  value = item;
}

void assign_function__SystemState__inbox_check_mode(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int8_t *>(
    get_function__SystemState__inbox_check_mode(untyped_member, index));
  const auto & value = *reinterpret_cast<const int8_t *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__eft(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__eft(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__eft(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__eft(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__eft(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__eft(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__eft(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__extend_io1_analog_in(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__SystemState__extend_io1_analog_in(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__extend_io1_analog_in(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__extend_io1_analog_in(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__extend_io1_analog_in(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__extend_io1_analog_in(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__extend_io1_analog_in(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__extend_io1_analog_out(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__SystemState__extend_io1_analog_out(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__extend_io1_analog_out(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__extend_io1_analog_out(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__extend_io1_analog_out(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__extend_io1_analog_out(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__extend_io1_analog_out(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__SystemState__aa_joint_ref(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__SystemState__aa_joint_ref(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__SystemState__aa_joint_ref(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__SystemState__aa_joint_ref(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__SystemState__aa_joint_ref(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__SystemState__aa_joint_ref(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__SystemState__aa_joint_ref(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SystemState_message_member_array[46] = {
  {
    "time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "jnt_ref",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, jnt_ref),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__jnt_ref,  // size() function pointer
    get_const_function__SystemState__jnt_ref,  // get_const(index) function pointer
    get_function__SystemState__jnt_ref,  // get(index) function pointer
    fetch_function__SystemState__jnt_ref,  // fetch(index, &value) function pointer
    assign_function__SystemState__jnt_ref,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "jnt_ang",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, jnt_ang),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__jnt_ang,  // size() function pointer
    get_const_function__SystemState__jnt_ang,  // get_const(index) function pointer
    get_function__SystemState__jnt_ang,  // get(index) function pointer
    fetch_function__SystemState__jnt_ang,  // fetch(index, &value) function pointer
    assign_function__SystemState__jnt_ang,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "jnt_cur",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, jnt_cur),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__jnt_cur,  // size() function pointer
    get_const_function__SystemState__jnt_cur,  // get_const(index) function pointer
    get_function__SystemState__jnt_cur,  // get(index) function pointer
    fetch_function__SystemState__jnt_cur,  // fetch(index, &value) function pointer
    assign_function__SystemState__jnt_cur,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tcp_ref",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, tcp_ref),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tcp_ref,  // size() function pointer
    get_const_function__SystemState__tcp_ref,  // get_const(index) function pointer
    get_function__SystemState__tcp_ref,  // get(index) function pointer
    fetch_function__SystemState__tcp_ref,  // fetch(index, &value) function pointer
    assign_function__SystemState__tcp_ref,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tcp_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, tcp_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tcp_pos,  // size() function pointer
    get_const_function__SystemState__tcp_pos,  // get_const(index) function pointer
    get_function__SystemState__tcp_pos,  // get(index) function pointer
    fetch_function__SystemState__tcp_pos,  // fetch(index, &value) function pointer
    assign_function__SystemState__tcp_pos,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "analog_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, analog_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__analog_in,  // size() function pointer
    get_const_function__SystemState__analog_in,  // get_const(index) function pointer
    get_function__SystemState__analog_in,  // get(index) function pointer
    fetch_function__SystemState__analog_in,  // fetch(index, &value) function pointer
    assign_function__SystemState__analog_in,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "analog_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, analog_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__analog_out,  // size() function pointer
    get_const_function__SystemState__analog_out,  // get_const(index) function pointer
    get_function__SystemState__analog_out,  // get(index) function pointer
    fetch_function__SystemState__analog_out,  // fetch(index, &value) function pointer
    assign_function__SystemState__analog_out,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "digital_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, digital_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__digital_in,  // size() function pointer
    get_const_function__SystemState__digital_in,  // get_const(index) function pointer
    get_function__SystemState__digital_in,  // get(index) function pointer
    fetch_function__SystemState__digital_in,  // fetch(index, &value) function pointer
    assign_function__SystemState__digital_in,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "digital_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, digital_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__digital_out,  // size() function pointer
    get_const_function__SystemState__digital_out,  // get_const(index) function pointer
    get_function__SystemState__digital_out,  // get(index) function pointer
    fetch_function__SystemState__digital_out,  // fetch(index, &value) function pointer
    assign_function__SystemState__digital_out,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "jnt_temperature",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, jnt_temperature),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__jnt_temperature,  // size() function pointer
    get_const_function__SystemState__jnt_temperature,  // get_const(index) function pointer
    get_function__SystemState__jnt_temperature,  // get(index) function pointer
    fetch_function__SystemState__jnt_temperature,  // fetch(index, &value) function pointer
    assign_function__SystemState__jnt_temperature,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_pc",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, task_pc),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_repeat",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, task_repeat),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_run_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, task_run_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_run_num",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, task_run_num),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_run_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, task_run_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "task_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, task_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "default_speed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, default_speed),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "robot_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, robot_state),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "information_chunk_1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, information_chunk_1),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "jnt_info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, jnt_info),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__jnt_info,  // size() function pointer
    get_const_function__SystemState__jnt_info,  // get_const(index) function pointer
    get_function__SystemState__jnt_info,  // get(index) function pointer
    fetch_function__SystemState__jnt_info,  // fetch(index, &value) function pointer
    assign_function__SystemState__jnt_info,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "collision_detect_onoff",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, collision_detect_onoff),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "is_freedrive_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, is_freedrive_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "real_vs_simulation_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, real_vs_simulation_mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "init_state_info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, init_state_info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "init_error",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, init_error),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tfb_analog_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, tfb_analog_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tfb_analog_in,  // size() function pointer
    get_const_function__SystemState__tfb_analog_in,  // get_const(index) function pointer
    get_function__SystemState__tfb_analog_in,  // get(index) function pointer
    fetch_function__SystemState__tfb_analog_in,  // fetch(index, &value) function pointer
    assign_function__SystemState__tfb_analog_in,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tfb_digital_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, tfb_digital_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tfb_digital_in,  // size() function pointer
    get_const_function__SystemState__tfb_digital_in,  // get_const(index) function pointer
    get_function__SystemState__tfb_digital_in,  // get(index) function pointer
    fetch_function__SystemState__tfb_digital_in,  // fetch(index, &value) function pointer
    assign_function__SystemState__tfb_digital_in,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tfb_digital_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, tfb_digital_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__tfb_digital_out,  // size() function pointer
    get_const_function__SystemState__tfb_digital_out,  // get_const(index) function pointer
    get_function__SystemState__tfb_digital_out,  // get(index) function pointer
    fetch_function__SystemState__tfb_digital_out,  // fetch(index, &value) function pointer
    assign_function__SystemState__tfb_digital_out,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tfb_voltage_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, tfb_voltage_out),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "op_stat_collision_occur",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, op_stat_collision_occur),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "op_stat_sos_flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, op_stat_sos_flag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "op_stat_self_collision",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, op_stat_self_collision),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "op_stat_soft_estop_occur",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, op_stat_soft_estop_occur),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "op_stat_ems_flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, op_stat_ems_flag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "information_chunk_2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, information_chunk_2),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "information_chunk_3",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, information_chunk_3),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "inbox_trap_flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, inbox_trap_flag),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__inbox_trap_flag,  // size() function pointer
    get_const_function__SystemState__inbox_trap_flag,  // get_const(index) function pointer
    get_function__SystemState__inbox_trap_flag,  // get(index) function pointer
    fetch_function__SystemState__inbox_trap_flag,  // fetch(index, &value) function pointer
    assign_function__SystemState__inbox_trap_flag,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "inbox_check_mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, inbox_check_mode),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__inbox_check_mode,  // size() function pointer
    get_const_function__SystemState__inbox_check_mode,  // get_const(index) function pointer
    get_function__SystemState__inbox_check_mode,  // get(index) function pointer
    fetch_function__SystemState__inbox_check_mode,  // fetch(index, &value) function pointer
    assign_function__SystemState__inbox_check_mode,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "eft",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, eft),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__eft,  // size() function pointer
    get_const_function__SystemState__eft,  // get_const(index) function pointer
    get_function__SystemState__eft,  // get(index) function pointer
    fetch_function__SystemState__eft,  // fetch(index, &value) function pointer
    assign_function__SystemState__eft,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "information_chunk_4",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, information_chunk_4),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "extend_io1_analog_in",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, extend_io1_analog_in),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__extend_io1_analog_in,  // size() function pointer
    get_const_function__SystemState__extend_io1_analog_in,  // get_const(index) function pointer
    get_function__SystemState__extend_io1_analog_in,  // get(index) function pointer
    fetch_function__SystemState__extend_io1_analog_in,  // fetch(index, &value) function pointer
    assign_function__SystemState__extend_io1_analog_in,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "extend_io1_analog_out",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, extend_io1_analog_out),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__extend_io1_analog_out,  // size() function pointer
    get_const_function__SystemState__extend_io1_analog_out,  // get_const(index) function pointer
    get_function__SystemState__extend_io1_analog_out,  // get(index) function pointer
    fetch_function__SystemState__extend_io1_analog_out,  // fetch(index, &value) function pointer
    assign_function__SystemState__extend_io1_analog_out,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "extend_io1_digital_info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, extend_io1_digital_info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "aa_joint_ref",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, aa_joint_ref),  // bytes offset in struct
    nullptr,  // default value
    size_function__SystemState__aa_joint_ref,  // size() function pointer
    get_const_function__SystemState__aa_joint_ref,  // get_const(index) function pointer
    get_function__SystemState__aa_joint_ref,  // get(index) function pointer
    fetch_function__SystemState__aa_joint_ref,  // fetch(index, &value) function pointer
    assign_function__SystemState__aa_joint_ref,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "safety_board_stat_info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rbpodo_msgs::msg::SystemState, safety_board_stat_info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SystemState_message_members = {
  "rbpodo_msgs::msg",  // message namespace
  "SystemState",  // message name
  46,  // number of fields
  sizeof(rbpodo_msgs::msg::SystemState),
  SystemState_message_member_array,  // message members
  SystemState_init_function,  // function to initialize message memory (memory has to be allocated)
  SystemState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SystemState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SystemState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rbpodo_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rbpodo_msgs::msg::SystemState>()
{
  return &::rbpodo_msgs::msg::rosidl_typesupport_introspection_cpp::SystemState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rbpodo_msgs, msg, SystemState)() {
  return &::rbpodo_msgs::msg::rosidl_typesupport_introspection_cpp::SystemState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
