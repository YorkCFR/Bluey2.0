// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluey_interface:srv/Motion.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__MOTION__STRUCT_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__MOTION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__bluey_interface__srv__Motion_Request __attribute__((deprecated))
#else
# define DEPRECATED__bluey_interface__srv__Motion_Request __declspec(deprecated)
#endif

namespace bluey_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Motion_Request_
{
  using Type = Motion_Request_<ContainerAllocator>;

  explicit Motion_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  explicit Motion_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _command_type command;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluey_interface::srv::Motion_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluey_interface::srv::Motion_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluey_interface::srv::Motion_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluey_interface::srv::Motion_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Motion_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Motion_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Motion_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Motion_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluey_interface::srv::Motion_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluey_interface::srv::Motion_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluey_interface__srv__Motion_Request
    std::shared_ptr<bluey_interface::srv::Motion_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluey_interface__srv__Motion_Request
    std::shared_ptr<bluey_interface::srv::Motion_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Motion_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    return true;
  }
  bool operator!=(const Motion_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Motion_Request_

// alias to use template instance with default allocator
using Motion_Request =
  bluey_interface::srv::Motion_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace bluey_interface


#ifndef _WIN32
# define DEPRECATED__bluey_interface__srv__Motion_Response __attribute__((deprecated))
#else
# define DEPRECATED__bluey_interface__srv__Motion_Response __declspec(deprecated)
#endif

namespace bluey_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Motion_Response_
{
  using Type = Motion_Response_<ContainerAllocator>;

  explicit Motion_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  explicit Motion_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluey_interface::srv::Motion_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluey_interface::srv::Motion_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluey_interface::srv::Motion_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluey_interface::srv::Motion_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Motion_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Motion_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Motion_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Motion_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluey_interface::srv::Motion_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluey_interface::srv::Motion_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluey_interface__srv__Motion_Response
    std::shared_ptr<bluey_interface::srv::Motion_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluey_interface__srv__Motion_Response
    std::shared_ptr<bluey_interface::srv::Motion_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Motion_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Motion_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Motion_Response_

// alias to use template instance with default allocator
using Motion_Response =
  bluey_interface::srv::Motion_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace bluey_interface

namespace bluey_interface
{

namespace srv
{

struct Motion
{
  using Request = bluey_interface::srv::Motion_Request;
  using Response = bluey_interface::srv::Motion_Response;
};

}  // namespace srv

}  // namespace bluey_interface

#endif  // BLUEY_INTERFACE__SRV__DETAIL__MOTION__STRUCT_HPP_
