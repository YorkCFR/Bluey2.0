// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluey_interface:srv/Motion.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__MOTION__BUILDER_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__MOTION__BUILDER_HPP_

#include "bluey_interface/srv/detail/motion__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace bluey_interface
{

namespace srv
{

namespace builder
{

class Init_Motion_Request_command
{
public:
  Init_Motion_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::bluey_interface::srv::Motion_Request command(::bluey_interface::srv::Motion_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluey_interface::srv::Motion_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluey_interface::srv::Motion_Request>()
{
  return bluey_interface::srv::builder::Init_Motion_Request_command();
}

}  // namespace bluey_interface


namespace bluey_interface
{

namespace srv
{

namespace builder
{

class Init_Motion_Response_result
{
public:
  Init_Motion_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::bluey_interface::srv::Motion_Response result(::bluey_interface::srv::Motion_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluey_interface::srv::Motion_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluey_interface::srv::Motion_Response>()
{
  return bluey_interface::srv::builder::Init_Motion_Response_result();
}

}  // namespace bluey_interface

#endif  // BLUEY_INTERFACE__SRV__DETAIL__MOTION__BUILDER_HPP_
