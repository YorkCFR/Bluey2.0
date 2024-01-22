// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluey_interface:srv/Lights.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__LIGHTS__STRUCT_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__LIGHTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__bluey_interface__srv__Lights_Request __attribute__((deprecated))
#else
# define DEPRECATED__bluey_interface__srv__Lights_Request __declspec(deprecated)
#endif

namespace bluey_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Lights_Request_
{
  using Type = Lights_Request_<ContainerAllocator>;

  explicit Lights_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->turn_on = false;
    }
  }

  explicit Lights_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->turn_on = false;
    }
  }

  // field types and members
  using _turn_on_type =
    bool;
  _turn_on_type turn_on;

  // setters for named parameter idiom
  Type & set__turn_on(
    const bool & _arg)
  {
    this->turn_on = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluey_interface::srv::Lights_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluey_interface::srv::Lights_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluey_interface::srv::Lights_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluey_interface::srv::Lights_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Lights_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Lights_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Lights_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Lights_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluey_interface::srv::Lights_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluey_interface::srv::Lights_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluey_interface__srv__Lights_Request
    std::shared_ptr<bluey_interface::srv::Lights_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluey_interface__srv__Lights_Request
    std::shared_ptr<bluey_interface::srv::Lights_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Lights_Request_ & other) const
  {
    if (this->turn_on != other.turn_on) {
      return false;
    }
    return true;
  }
  bool operator!=(const Lights_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Lights_Request_

// alias to use template instance with default allocator
using Lights_Request =
  bluey_interface::srv::Lights_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace bluey_interface


#ifndef _WIN32
# define DEPRECATED__bluey_interface__srv__Lights_Response __attribute__((deprecated))
#else
# define DEPRECATED__bluey_interface__srv__Lights_Response __declspec(deprecated)
#endif

namespace bluey_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Lights_Response_
{
  using Type = Lights_Response_<ContainerAllocator>;

  explicit Lights_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Lights_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    bluey_interface::srv::Lights_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluey_interface::srv::Lights_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluey_interface::srv::Lights_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluey_interface::srv::Lights_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Lights_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Lights_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Lights_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Lights_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluey_interface::srv::Lights_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluey_interface::srv::Lights_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluey_interface__srv__Lights_Response
    std::shared_ptr<bluey_interface::srv::Lights_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluey_interface__srv__Lights_Response
    std::shared_ptr<bluey_interface::srv::Lights_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Lights_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Lights_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Lights_Response_

// alias to use template instance with default allocator
using Lights_Response =
  bluey_interface::srv::Lights_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace bluey_interface

namespace bluey_interface
{

namespace srv
{

struct Lights
{
  using Request = bluey_interface::srv::Lights_Request;
  using Response = bluey_interface::srv::Lights_Response;
};

}  // namespace srv

}  // namespace bluey_interface

#endif  // BLUEY_INTERFACE__SRV__DETAIL__LIGHTS__STRUCT_HPP_
