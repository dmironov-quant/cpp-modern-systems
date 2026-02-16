#pragma once

#include <cstdint>

template <std::size_t N>
struct Factorial {
    static constexpr std::uint64_t value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static constexpr std::uint64_t value = 1;
};
