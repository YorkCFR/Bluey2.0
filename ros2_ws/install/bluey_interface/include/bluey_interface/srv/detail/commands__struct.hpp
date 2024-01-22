// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bluey_interface:srv/Commands.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__STRUCT_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__bluey_interface__srv__Commands_Request __attribute__((deprecated))
#else
# define DEPRECATED__bluey_interface__srv__Commands_Request __declspec(deprecated)
#endif

namespace bluey_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Commands_Request_
{
  using Type = Commands_Request_<ContainerAllocator>;

  explicit Commands_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->arg = "";
    }
  }

  explicit Commands_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc),
    arg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->arg = "";
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _command_type command;
  using _arg_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _arg_type arg;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__arg(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->arg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluey_interface::srv::Commands_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluey_interface::srv::Commands_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluey_interface::srv::Commands_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluey_interface::srv::Commands_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Commands_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Commands_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Commands_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Commands_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluey_interface::srv::Commands_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluey_interface::srv::Commands_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluey_interface__srv__Commands_Request
    std::shared_ptr<bluey_interface::srv::Commands_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluey_interface__srv__Commands_Request
    std::shared_ptr<bluey_interface::srv::Commands_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Commands_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->arg != other.arg) {
      return false;
    }
    return true;
  }
  bool operator!=(const Commands_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Commands_Request_

// alias to use template instance with default allocator
using Commands_Request =
  bluey_interface::srv::Commands_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace bluey_interface


#ifndef _WIN32
# define DEPRECATED__bluey_interface__srv__Commands_Response __attribute__((deprecated))
#else
# define DEPRECATED__bluey_interface__srv__Commands_Response __declspec(deprecated)
#endif

namespace bluey_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Commands_Response_
{
  using Type = Commands_Response_<ContainerAllocator>;

  explicit Commands_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
      this->status = false;
    }
  }

  explicit Commands_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
      this->status = false;
    }
  }

  // field types and members
  using _result_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _result_type result;
  using _status_type =
    bool;
  _status_type status;

  // setters for named parameter idiom
  Type & set__result(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->result = _arg;
    return *this;
  }
  Type & set__status(
    const bool & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    bluey_interface::srv::Commands_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const bluey_interface::srv::Commands_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bluey_interface::srv::Commands_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bluey_interface::srv::Commands_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Commands_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Commands_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bluey_interface::srv::Commands_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bluey_interface::srv::Commands_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bluey_interface::srv::Commands_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bluey_interface::srv::Commands_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bluey_interface__srv__Commands_Response
    std::shared_ptr<bluey_interface::srv::Commands_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bluey_interface__srv__Commands_Response
    std::shared_ptr<bluey_interface::srv::Commands_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Commands_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Commands_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Commands_Response_

// alias to use template instance with default allocator
using Commands_Response =
  bluey_interface::srv::Commands_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace bluey_interface

namespace bluey_interface
{

namespace srv
{

struct Commands
{
  using Request = bluey_interface::srv::Commands_Request;
  using Response = bluey_interface::srv::Commands_Response;
};

}  // namespace srv

}  // namespace bluey_interface

#endif  // BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__STRUCT_HPP_
