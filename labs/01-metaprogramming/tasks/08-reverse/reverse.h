#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

template <typename T>
concept Reversable =
    std::ranges::bidirectional_range<T> &&
    std::permutable<std::ranges::iterator_t<T>>;

template <typename T>
void Reverse(T& t) {
    if constexpr (Reversable<T>) {
        std::reverse(std::begin(t), std::end(t));
    }
    else {
    }
}