// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluey_interface:srv/Arm.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__ARM__STRUCT_H_
#define BLUEY_INTERFACE__SRV__DETAIL__ARM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Arm in the package bluey_interface.
typedef struct bluey_interface__srv__Arm_Request
{
  bool arm;
} bluey_interface__srv__Arm_Request;

// Struct for a sequence of bluey_interface__srv__Arm_Request.
typedef struct bluey_interface__srv__Arm_Request__Sequence
{
  bluey_interface__srv__Arm_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluey_interface__srv__Arm_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Arm in the package bluey_interface.
typedef struct bluey_interface__srv__Arm_Response
{
  uint8_t structure_needs_at_least_one_member;
} bluey_interface__srv__Arm_Response;

// Struct for a sequence of bluey_interface__srv__Arm_Response.
typedef struct bluey_interface__srv__Arm_Response__Sequence
{
  bluey_interface__srv__Arm_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluey_interface__srv__Arm_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEY_INTERFACE__SRV__DETAIL__ARM__STRUCT_H_
