#pragma once
#include <type_traits>
#include <cstdint>

template <typename T>
struct is_integral : std::false_type {};

template <> struct is_integral<bool>          : std::true_type {};
template <> struct is_integral<char>          : std::true_type {};
template <> struct is_integral<int>           : std::true_type {};
template <> struct is_integral<long>          : std::true_type {};
template <> struct is_integral<long long>     : std::true_type {};
template <> struct is_integral<std::int8_t>   : std::true_type {};
template <> struct is_integral<std::int16_t>  : std::true_type {};
template <> struct is_integral<std::uint8_t>  : std::true_type {};
template <> struct is_integral<std::uint16_t> : std::true_type {};
template <> struct is_integral<std::uint32_t> : std::true_type {};
template <> struct is_integral<std::uint64_t> : std::true_type {};

template <typename T>
inline constexpr bool is_integral_v = is_integral<T>::value;