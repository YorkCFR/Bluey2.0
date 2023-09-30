// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluey_interface:srv/Lights.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__LIGHTS__BUILDER_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__LIGHTS__BUILDER_HPP_

#include "bluey_interface/srv/detail/lights__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace bluey_interface
{

namespace srv
{

namespace builder
{

class Init_Lights_Request_turn_on
{
public:
  Init_Lights_Request_turn_on()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::bluey_interface::srv::Lights_Request turn_on(::bluey_interface::srv::Lights_Request::_turn_on_type arg)
  {
    msg_.turn_on = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluey_interface::srv::Lights_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluey_interface::srv::Lights_Request>()
{
  return bluey_interface::srv::builder::Init_Lights_Request_turn_on();
}

}  // namespace bluey_interface


namespace bluey_interface
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluey_interface::srv::Lights_Response>()
{
  return ::bluey_interface::srv::Lights_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace bluey_interface

#endif  // BLUEY_INTERFACE__SRV__DETAIL__LIGHTS__BUILDER_HPP_
