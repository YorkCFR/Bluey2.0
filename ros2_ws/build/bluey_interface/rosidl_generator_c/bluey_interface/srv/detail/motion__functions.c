// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bluey_interface:srv/Motion.idl
// generated code does not contain a copyright notice
#include "bluey_interface/srv/detail/motion__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

bool
bluey_interface__srv__Motion_Request__init(bluey_interface__srv__Motion_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    bluey_interface__srv__Motion_Request__fini(msg);
    return false;
  }
  return true;
}

void
bluey_interface__srv__Motion_Request__fini(bluey_interface__srv__Motion_Request * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
}

bool
bluey_interface__srv__Motion_Request__are_equal(const bluey_interface__srv__Motion_Request * lhs, const bluey_interface__srv__Motion_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  return true;
}

bool
bluey_interface__srv__Motion_Request__copy(
  const bluey_interface__srv__Motion_Request * input,
  bluey_interface__srv__Motion_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  return true;
}

bluey_interface__srv__Motion_Request *
bluey_interface__srv__Motion_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluey_interface__srv__Motion_Request * msg = (bluey_interface__srv__Motion_Request *)allocator.allocate(sizeof(bluey_interface__srv__Motion_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bluey_interface__srv__Motion_Request));
  bool success = bluey_interface__srv__Motion_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bluey_interface__srv__Motion_Request__destroy(bluey_interface__srv__Motion_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bluey_interface__srv__Motion_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bluey_interface__srv__Motion_Request__Sequence__init(bluey_interface__srv__Motion_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluey_interface__srv__Motion_Request * data = NULL;

  if (size) {
    data = (bluey_interface__srv__Motion_Request *)allocator.zero_allocate(size, sizeof(bluey_interface__srv__Motion_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bluey_interface__srv__Motion_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bluey_interface__srv__Motion_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
bluey_interface__srv__Motion_Request__Sequence__fini(bluey_interface__srv__Motion_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      bluey_interface__srv__Motion_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

bluey_interface__srv__Motion_Request__Sequence *
bluey_interface__srv__Motion_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluey_interface__srv__Motion_Request__Sequence * array = (bluey_interface__srv__Motion_Request__Sequence *)allocator.allocate(sizeof(bluey_interface__srv__Motion_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bluey_interface__srv__Motion_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bluey_interface__srv__Motion_Request__Sequence__destroy(bluey_interface__srv__Motion_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bluey_interface__srv__Motion_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bluey_interface__srv__Motion_Request__Sequence__are_equal(const bluey_interface__srv__Motion_Request__Sequence * lhs, const bluey_interface__srv__Motion_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bluey_interface__srv__Motion_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bluey_interface__srv__Motion_Request__Sequence__copy(
  const bluey_interface__srv__Motion_Request__Sequence * input,
  bluey_interface__srv__Motion_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bluey_interface__srv__Motion_Request);
    bluey_interface__srv__Motion_Request * data =
      (bluey_interface__srv__Motion_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bluey_interface__srv__Motion_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          bluey_interface__srv__Motion_Request__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bluey_interface__srv__Motion_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
bluey_interface__srv__Motion_Response__init(bluey_interface__srv__Motion_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
bluey_interface__srv__Motion_Response__fini(bluey_interface__srv__Motion_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
bluey_interface__srv__Motion_Response__are_equal(const bluey_interface__srv__Motion_Response * lhs, const bluey_interface__srv__Motion_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
bluey_interface__srv__Motion_Response__copy(
  const bluey_interface__srv__Motion_Response * input,
  bluey_interface__srv__Motion_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

bluey_interface__srv__Motion_Response *
bluey_interface__srv__Motion_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluey_interface__srv__Motion_Response * msg = (bluey_interface__srv__Motion_Response *)allocator.allocate(sizeof(bluey_interface__srv__Motion_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bluey_interface__srv__Motion_Response));
  bool success = bluey_interface__srv__Motion_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bluey_interface__srv__Motion_Response__destroy(bluey_interface__srv__Motion_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bluey_interface__srv__Motion_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bluey_interface__srv__Motion_Response__Sequence__init(bluey_interface__srv__Motion_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluey_interface__srv__Motion_Response * data = NULL;

  if (size) {
    data = (bluey_interface__srv__Motion_Response *)allocator.zero_allocate(size, sizeof(bluey_interface__srv__Motion_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bluey_interface__srv__Motion_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bluey_interface__srv__Motion_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
bluey_interface__srv__Motion_Response__Sequence__fini(bluey_interface__srv__Motion_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      bluey_interface__srv__Motion_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

bluey_interface__srv__Motion_Response__Sequence *
bluey_interface__srv__Motion_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bluey_interface__srv__Motion_Response__Sequence * array = (bluey_interface__srv__Motion_Response__Sequence *)allocator.allocate(sizeof(bluey_interface__srv__Motion_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bluey_interface__srv__Motion_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bluey_interface__srv__Motion_Response__Sequence__destroy(bluey_interface__srv__Motion_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bluey_interface__srv__Motion_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bluey_interface__srv__Motion_Response__Sequence__are_equal(const bluey_interface__srv__Motion_Response__Sequence * lhs, const bluey_interface__srv__Motion_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bluey_interface__srv__Motion_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bluey_interface__srv__Motion_Response__Sequence__copy(
  const bluey_interface__srv__Motion_Response__Sequence * input,
  bluey_interface__srv__Motion_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bluey_interface__srv__Motion_Response);
    bluey_interface__srv__Motion_Response * data =
      (bluey_interface__srv__Motion_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bluey_interface__srv__Motion_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          bluey_interface__srv__Motion_Response__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bluey_interface__srv__Motion_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
