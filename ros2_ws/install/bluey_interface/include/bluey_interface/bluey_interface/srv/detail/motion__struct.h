// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluey_interface:srv/Motion.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__MOTION__STRUCT_H_
#define BLUEY_INTERFACE__SRV__DETAIL__MOTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Motion in the package bluey_interface.
typedef struct bluey_interface__srv__Motion_Request
{
  rosidl_runtime_c__String command;
} bluey_interface__srv__Motion_Request;

// Struct for a sequence of bluey_interface__srv__Motion_Request.
typedef struct bluey_interface__srv__Motion_Request__Sequence
{
  bluey_interface__srv__Motion_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluey_interface__srv__Motion_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Motion in the package bluey_interface.
typedef struct bluey_interface__srv__Motion_Response
{
  bool result;
} bluey_interface__srv__Motion_Response;

// Struct for a sequence of bluey_interface__srv__Motion_Response.
typedef struct bluey_interface__srv__Motion_Response__Sequence
{
  bluey_interface__srv__Motion_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluey_interface__srv__Motion_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEY_INTERFACE__SRV__DETAIL__MOTION__STRUCT_H_
