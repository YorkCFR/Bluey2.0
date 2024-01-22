// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from bluey_interface:srv/Commands.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__FUNCTIONS_H_
#define BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "bluey_interface/msg/rosidl_generator_c__visibility_control.h"

#include "bluey_interface/srv/detail/commands__struct.h"

/// Initialize srv/Commands message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bluey_interface__srv__Commands_Request
 * )) before or use
 * bluey_interface__srv__Commands_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Request__init(bluey_interface__srv__Commands_Request * msg);

/// Finalize srv/Commands message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
void
bluey_interface__srv__Commands_Request__fini(bluey_interface__srv__Commands_Request * msg);

/// Create srv/Commands message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bluey_interface__srv__Commands_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bluey_interface__srv__Commands_Request *
bluey_interface__srv__Commands_Request__create();

/// Destroy srv/Commands message.
/**
 * It calls
 * bluey_interface__srv__Commands_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
void
bluey_interface__srv__Commands_Request__destroy(bluey_interface__srv__Commands_Request * msg);

/// Check for srv/Commands message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Request__are_equal(const bluey_interface__srv__Commands_Request * lhs, const bluey_interface__srv__Commands_Request * rhs);

/// Copy a srv/Commands message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Request__copy(
  const bluey_interface__srv__Commands_Request * input,
  bluey_interface__srv__Commands_Request * output);

/// Initialize array of srv/Commands messages.
/**
 * It allocates the memory for the number of elements and calls
 * bluey_interface__srv__Commands_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Request__Sequence__init(bluey_interface__srv__Commands_Request__Sequence * array, size_t size);

/// Finalize array of srv/Commands messages.
/**
 * It calls
 * bluey_interface__srv__Commands_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
void
bluey_interface__srv__Commands_Request__Sequence__fini(bluey_interface__srv__Commands_Request__Sequence * array);

/// Create array of srv/Commands messages.
/**
 * It allocates the memory for the array and calls
 * bluey_interface__srv__Commands_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bluey_interface__srv__Commands_Request__Sequence *
bluey_interface__srv__Commands_Request__Sequence__create(size_t size);

/// Destroy array of srv/Commands messages.
/**
 * It calls
 * bluey_interface__srv__Commands_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
void
bluey_interface__srv__Commands_Request__Sequence__destroy(bluey_interface__srv__Commands_Request__Sequence * array);

/// Check for srv/Commands message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Request__Sequence__are_equal(const bluey_interface__srv__Commands_Request__Sequence * lhs, const bluey_interface__srv__Commands_Request__Sequence * rhs);

/// Copy an array of srv/Commands messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Request__Sequence__copy(
  const bluey_interface__srv__Commands_Request__Sequence * input,
  bluey_interface__srv__Commands_Request__Sequence * output);

/// Initialize srv/Commands message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bluey_interface__srv__Commands_Response
 * )) before or use
 * bluey_interface__srv__Commands_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Response__init(bluey_interface__srv__Commands_Response * msg);

/// Finalize srv/Commands message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
void
bluey_interface__srv__Commands_Response__fini(bluey_interface__srv__Commands_Response * msg);

/// Create srv/Commands message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bluey_interface__srv__Commands_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bluey_interface__srv__Commands_Response *
bluey_interface__srv__Commands_Response__create();

/// Destroy srv/Commands message.
/**
 * It calls
 * bluey_interface__srv__Commands_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
void
bluey_interface__srv__Commands_Response__destroy(bluey_interface__srv__Commands_Response * msg);

/// Check for srv/Commands message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Response__are_equal(const bluey_interface__srv__Commands_Response * lhs, const bluey_interface__srv__Commands_Response * rhs);

/// Copy a srv/Commands message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Response__copy(
  const bluey_interface__srv__Commands_Response * input,
  bluey_interface__srv__Commands_Response * output);

/// Initialize array of srv/Commands messages.
/**
 * It allocates the memory for the number of elements and calls
 * bluey_interface__srv__Commands_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Response__Sequence__init(bluey_interface__srv__Commands_Response__Sequence * array, size_t size);

/// Finalize array of srv/Commands messages.
/**
 * It calls
 * bluey_interface__srv__Commands_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
void
bluey_interface__srv__Commands_Response__Sequence__fini(bluey_interface__srv__Commands_Response__Sequence * array);

/// Create array of srv/Commands messages.
/**
 * It allocates the memory for the array and calls
 * bluey_interface__srv__Commands_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bluey_interface__srv__Commands_Response__Sequence *
bluey_interface__srv__Commands_Response__Sequence__create(size_t size);

/// Destroy array of srv/Commands messages.
/**
 * It calls
 * bluey_interface__srv__Commands_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
void
bluey_interface__srv__Commands_Response__Sequence__destroy(bluey_interface__srv__Commands_Response__Sequence * array);

/// Check for srv/Commands message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Response__Sequence__are_equal(const bluey_interface__srv__Commands_Response__Sequence * lhs, const bluey_interface__srv__Commands_Response__Sequence * rhs);

/// Copy an array of srv/Commands messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bluey_interface
bool
bluey_interface__srv__Commands_Response__Sequence__copy(
  const bluey_interface__srv__Commands_Response__Sequence * input,
  bluey_interface__srv__Commands_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__FUNCTIONS_H_
