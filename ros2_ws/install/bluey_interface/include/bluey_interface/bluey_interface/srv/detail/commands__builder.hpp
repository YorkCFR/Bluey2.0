// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluey_interface:srv/Commands.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__BUILDER_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluey_interface/srv/detail/commands__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluey_interface
{

namespace srv
{

namespace builder
{

class Init_Commands_Request_arg
{
public:
  explicit Init_Commands_Request_arg(::bluey_interface::srv::Commands_Request & msg)
  : msg_(msg)
  {}
  ::bluey_interface::srv::Commands_Request arg(::bluey_interface::srv::Commands_Request::_arg_type arg)
  {
    msg_.arg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluey_interface::srv::Commands_Request msg_;
};

class Init_Commands_Request_command
{
public:
  Init_Commands_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Commands_Request_arg command(::bluey_interface::srv::Commands_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_Commands_Request_arg(msg_);
  }

private:
  ::bluey_interface::srv::Commands_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluey_interface::srv::Commands_Request>()
{
  return bluey_interface::srv::builder::Init_Commands_Request_command();
}

}  // namespace bluey_interface


namespace bluey_interface
{

namespace srv
{

namespace builder
{

class Init_Commands_Response_status
{
public:
  explicit Init_Commands_Response_status(::bluey_interface::srv::Commands_Response & msg)
  : msg_(msg)
  {}
  ::bluey_interface::srv::Commands_Response status(::bluey_interface::srv::Commands_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluey_interface::srv::Commands_Response msg_;
};

class Init_Commands_Response_result
{
public:
  Init_Commands_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Commands_Response_status result(::bluey_interface::srv::Commands_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_Commands_Response_status(msg_);
  }

private:
  ::bluey_interface::srv::Commands_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluey_interface::srv::Commands_Response>()
{
  return bluey_interface::srv::builder::Init_Commands_Response_result();
}

}  // namespace bluey_interface

#endif  // BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__BUILDER_HPP_
