// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from bluey_interface:srv/Lights.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "bluey_interface/srv/detail/lights__rosidl_typesupport_introspection_c.h"
#include "bluey_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "bluey_interface/srv/detail/lights__functions.h"
#include "bluey_interface/srv/detail/lights__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  bluey_interface__srv__Lights_Request__init(message_memory);
}

void Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_fini_function(void * message_memory)
{
  bluey_interface__srv__Lights_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_message_member_array[1] = {
  {
    "turn_on",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bluey_interface__srv__Lights_Request, turn_on),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_message_members = {
  "bluey_interface__srv",  // message namespace
  "Lights_Request",  // message name
  1,  // number of fields
  sizeof(bluey_interface__srv__Lights_Request),
  Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_message_member_array,  // message members
  Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_message_type_support_handle = {
  0,
  &Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_bluey_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bluey_interface, srv, Lights_Request)() {
  if (!Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_message_type_support_handle.typesupport_identifier) {
    Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Lights_Request__rosidl_typesupport_introspection_c__Lights_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "bluey_interface/srv/detail/lights__rosidl_typesupport_introspection_c.h"
// already included above
// #include "bluey_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "bluey_interface/srv/detail/lights__functions.h"
// already included above
// #include "bluey_interface/srv/detail/lights__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  bluey_interface__srv__Lights_Response__init(message_memory);
}

void Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_fini_function(void * message_memory)
{
  bluey_interface__srv__Lights_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(bluey_interface__srv__Lights_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_message_members = {
  "bluey_interface__srv",  // message namespace
  "Lights_Response",  // message name
  1,  // number of fields
  sizeof(bluey_interface__srv__Lights_Response),
  Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_message_member_array,  // message members
  Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_message_type_support_handle = {
  0,
  &Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_bluey_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bluey_interface, srv, Lights_Response)() {
  if (!Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_message_type_support_handle.typesupport_identifier) {
    Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Lights_Response__rosidl_typesupport_introspection_c__Lights_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "bluey_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "bluey_interface/srv/detail/lights__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_service_members = {
  "bluey_interface__srv",  // service namespace
  "Lights",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_Request_message_type_support_handle,
  NULL  // response message
  // bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_Response_message_type_support_handle
};

static rosidl_service_type_support_t bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_service_type_support_handle = {
  0,
  &bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bluey_interface, srv, Lights_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bluey_interface, srv, Lights_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_bluey_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bluey_interface, srv, Lights)() {
  if (!bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_service_type_support_handle.typesupport_identifier) {
    bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bluey_interface, srv, Lights_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, bluey_interface, srv, Lights_Response)()->data;
  }

  return &bluey_interface__srv__detail__lights__rosidl_typesupport_introspection_c__Lights_service_type_support_handle;
}
