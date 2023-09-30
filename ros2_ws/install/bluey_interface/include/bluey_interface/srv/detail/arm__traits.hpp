// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bluey_interface:srv/Arm.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__ARM__TRAITS_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__ARM__TRAITS_HPP_

#include "bluey_interface/srv/detail/arm__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bluey_interface::srv::Arm_Request>()
{
  return "bluey_interface::srv::Arm_Request";
}

template<>
inline const char * name<bluey_interface::srv::Arm_Request>()
{
  return "bluey_interface/srv/Arm_Request";
}

template<>
struct has_fixed_size<bluey_interface::srv::Arm_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bluey_interface::srv::Arm_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bluey_interface::srv::Arm_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bluey_interface::srv::Arm_Response>()
{
  return "bluey_interface::srv::Arm_Response";
}

template<>
inline const char * name<bluey_interface::srv::Arm_Response>()
{
  return "bluey_interface/srv/Arm_Response";
}

template<>
struct has_fixed_size<bluey_interface::srv::Arm_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bluey_interface::srv::Arm_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bluey_interface::srv::Arm_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bluey_interface::srv::Arm>()
{
  return "bluey_interface::srv::Arm";
}

template<>
inline const char * name<bluey_interface::srv::Arm>()
{
  return "bluey_interface/srv/Arm";
}

template<>
struct has_fixed_size<bluey_interface::srv::Arm>
  : std::integral_constant<
    bool,
    has_fixed_size<bluey_interface::srv::Arm_Request>::value &&
    has_fixed_size<bluey_interface::srv::Arm_Response>::value
  >
{
};

template<>
struct has_bounded_size<bluey_interface::srv::Arm>
  : std::integral_constant<
    bool,
    has_bounded_size<bluey_interface::srv::Arm_Request>::value &&
    has_bounded_size<bluey_interface::srv::Arm_Response>::value
  >
{
};

template<>
struct is_service<bluey_interface::srv::Arm>
  : std::true_type
{
};

template<>
struct is_service_request<bluey_interface::srv::Arm_Request>
  : std::true_type
{
};

template<>
struct is_service_response<bluey_interface::srv::Arm_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BLUEY_INTERFACE__SRV__DETAIL__ARM__TRAITS_HPP_
