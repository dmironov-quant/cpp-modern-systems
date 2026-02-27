#pragma once

#include <algorithm>
#include <ranges>
#include <type_traits>
#include <utility>   // std::declval
#include <vector>
#include <set>
#include <iostream>

template <typename T, typename = void>
struct is_reversable : std::false_type {};

template <typename T>
struct is_reversable<T, std::void_t<decltype(std::ranges::reverse(std::declval<T&>()))>> : std::true_type {};

template <typename T>
inline constexpr bool is_reversable_v = is_reversable<T>::value;

template <typename T, std::enable_if_t<is_reversable_v<T>, int> = 0>
void Reverse(T& obj) {
    std::ranges::reverse(obj);
}

template <typename T, std::enable_if_t<!is_reversable_v<T>, int> = 0>
void Reverse(T& obj) {
}