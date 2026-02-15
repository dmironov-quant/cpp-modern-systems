#pragma once

#include <cstddef>

template <typename C>
concept HasReserve = requires(C& c, std::size_t n) { c.reserve(n); };

template <typename C>
void UniversalReserve(C& c, std::size_t n) {
    if constexpr (HasReserve<C>) {
        c.reserve(n);
    }
    else {
        (void)c;
        (void)n;
    }
}

