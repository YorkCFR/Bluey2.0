// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bluey_interface:srv/Arm.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__ARM__BUILDER_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__ARM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bluey_interface/srv/detail/arm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bluey_interface
{

namespace srv
{

namespace builder
{

class Init_Arm_Request_arm
{
public:
  Init_Arm_Request_arm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::bluey_interface::srv::Arm_Request arm(::bluey_interface::srv::Arm_Request::_arm_type arg)
  {
    msg_.arm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bluey_interface::srv::Arm_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::bluey_interface::srv::Arm_Request>()
{
  return bluey_interface::srv::builder::Init_Arm_Request_arm();
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
auto build<::bluey_interface::srv::Arm_Response>()
{
  return ::bluey_interface::srv::Arm_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace bluey_interface

#endif  // BLUEY_INTERFACE__SRV__DETAIL__ARM__BUILDER_HPP_
