// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bluey_interface:srv/Commands.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__TRAITS_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__TRAITS_HPP_

#include "bluey_interface/srv/detail/commands__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bluey_interface::srv::Commands_Request>()
{
  return "bluey_interface::srv::Commands_Request";
}

template<>
inline const char * name<bluey_interface::srv::Commands_Request>()
{
  return "bluey_interface/srv/Commands_Request";
}

template<>
struct has_fixed_size<bluey_interface::srv::Commands_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<bluey_interface::srv::Commands_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<bluey_interface::srv::Commands_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bluey_interface::srv::Commands_Response>()
{
  return "bluey_interface::srv::Commands_Response";
}

template<>
inline const char * name<bluey_interface::srv::Commands_Response>()
{
  return "bluey_interface/srv/Commands_Response";
}

template<>
struct has_fixed_size<bluey_interface::srv::Commands_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<bluey_interface::srv::Commands_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<bluey_interface::srv::Commands_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bluey_interface::srv::Commands>()
{
  return "bluey_interface::srv::Commands";
}

template<>
inline const char * name<bluey_interface::srv::Commands>()
{
  return "bluey_interface/srv/Commands";
}

template<>
struct has_fixed_size<bluey_interface::srv::Commands>
  : std::integral_constant<
    bool,
    has_fixed_size<bluey_interface::srv::Commands_Request>::value &&
    has_fixed_size<bluey_interface::srv::Commands_Response>::value
  >
{
};

template<>
struct has_bounded_size<bluey_interface::srv::Commands>
  : std::integral_constant<
    bool,
    has_bounded_size<bluey_interface::srv::Commands_Request>::value &&
    has_bounded_size<bluey_interface::srv::Commands_Response>::value
  >
{
};

template<>
struct is_service<bluey_interface::srv::Commands>
  : std::true_type
{
};

template<>
struct is_service_request<bluey_interface::srv::Commands_Request>
  : std::true_type
{
};

template<>
struct is_service_response<bluey_interface::srv::Commands_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BLUEY_INTERFACE__SRV__DETAIL__COMMANDS__TRAITS_HPP_
