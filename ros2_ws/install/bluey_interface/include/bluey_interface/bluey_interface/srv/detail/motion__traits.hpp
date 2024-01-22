// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bluey_interface:srv/Motion.idl
// generated code does not contain a copyright notice

#ifndef BLUEY_INTERFACE__SRV__DETAIL__MOTION__TRAITS_HPP_
#define BLUEY_INTERFACE__SRV__DETAIL__MOTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bluey_interface/srv/detail/motion__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace bluey_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Motion_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Motion_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Motion_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace bluey_interface

namespace rosidl_generator_traits
{

[[deprecated("use bluey_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const bluey_interface::srv::Motion_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  bluey_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bluey_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const bluey_interface::srv::Motion_Request & msg)
{
  return bluey_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<bluey_interface::srv::Motion_Request>()
{
  return "bluey_interface::srv::Motion_Request";
}

template<>
inline const char * name<bluey_interface::srv::Motion_Request>()
{
  return "bluey_interface/srv/Motion_Request";
}

template<>
struct has_fixed_size<bluey_interface::srv::Motion_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<bluey_interface::srv::Motion_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<bluey_interface::srv::Motion_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace bluey_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Motion_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Motion_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Motion_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace bluey_interface

namespace rosidl_generator_traits
{

[[deprecated("use bluey_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const bluey_interface::srv::Motion_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  bluey_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bluey_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const bluey_interface::srv::Motion_Response & msg)
{
  return bluey_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<bluey_interface::srv::Motion_Response>()
{
  return "bluey_interface::srv::Motion_Response";
}

template<>
inline const char * name<bluey_interface::srv::Motion_Response>()
{
  return "bluey_interface/srv/Motion_Response";
}

template<>
struct has_fixed_size<bluey_interface::srv::Motion_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<bluey_interface::srv::Motion_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<bluey_interface::srv::Motion_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<bluey_interface::srv::Motion>()
{
  return "bluey_interface::srv::Motion";
}

template<>
inline const char * name<bluey_interface::srv::Motion>()
{
  return "bluey_interface/srv/Motion";
}

template<>
struct has_fixed_size<bluey_interface::srv::Motion>
  : std::integral_constant<
    bool,
    has_fixed_size<bluey_interface::srv::Motion_Request>::value &&
    has_fixed_size<bluey_interface::srv::Motion_Response>::value
  >
{
};

template<>
struct has_bounded_size<bluey_interface::srv::Motion>
  : std::integral_constant<
    bool,
    has_bounded_size<bluey_interface::srv::Motion_Request>::value &&
    has_bounded_size<bluey_interface::srv::Motion_Response>::value
  >
{
};

template<>
struct is_service<bluey_interface::srv::Motion>
  : std::true_type
{
};

template<>
struct is_service_request<bluey_interface::srv::Motion_Request>
  : std::true_type
{
};

template<>
struct is_service_response<bluey_interface::srv::Motion_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // BLUEY_INTERFACE__SRV__DETAIL__MOTION__TRAITS_HPP_
