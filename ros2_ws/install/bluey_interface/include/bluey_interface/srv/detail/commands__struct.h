// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bluey_interface:srv/Commands.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__STRUCT_H_
#define BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__STRUCT_H_

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
// Member 'arg'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/Commands in the package bluey_interface.
typedef struct bluey_interface__srv__Commands_Request
{
  rosidl_runtime_c__String command;
  rosidl_runtime_c__String arg;
} bluey_interface__srv__Commands_Request;

// Struct for a sequence of bluey_interface__srv__Commands_Request.
typedef struct bluey_interface__srv__Commands_Request__Sequence
{
  bluey_interface__srv__Commands_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluey_interface__srv__Commands_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/Commands in the package bluey_interface.
typedef struct bluey_interface__srv__Commands_Response
{
  rosidl_runtime_c__String result;
  bool status;
} bluey_interface__srv__Commands_Response;

// Struct for a sequence of bluey_interface__srv__Commands_Response.
typedef struct bluey_interface__srv__Commands_Response__Sequence
{
  bluey_interface__srv__Commands_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bluey_interface__srv__Commands_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__STRUCT_H_
