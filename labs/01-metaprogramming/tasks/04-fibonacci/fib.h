#pragma once
#include <cstdint>

template <std::size_t N>
struct Fib {
    static constexpr std::uint64_t value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template <>
struct Fib<0> {
    static constexpr std::uint64_t value = 0;
};

template <>
struct Fib<1> {
    static constexpr std::uint64_t value = 1;
};