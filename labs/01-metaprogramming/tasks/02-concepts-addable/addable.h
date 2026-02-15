#pragma once

#include <vector>
#include <concepts>

template <typename T>
concept Addable = requires(const T& a, const T& b) { { a + b } -> std::convertible_to<T> ; };

template <typename T>
requires Addable<T> && std::default_initializable<T>
T SumAll(const std::vector<T>& v) {
    T res{};
    for (const auto& el : v) {
        res = res + el;
    }
    return res;
}

template <typename>
inline constexpr bool dependent_false_v = false;

template <typename T>
requires (!Addable<T>)
T SumAll(const std::vector<T>& v) {
    static_assert(dependent_false_v<T>,
        "SumAll<T> requires Addable<T> : expression (a + b) must be valid and convertible to T"
    );
    return {};
}