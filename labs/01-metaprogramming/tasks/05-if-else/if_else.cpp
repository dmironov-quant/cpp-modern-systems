#include "if_else.h"

#include <iostream>
#include <type_traits>
#include <cstdint>
#include <vector>
#include <string>

int main() {
    static_assert(std::is_same_v<if_else_t<true, int, int>, int>);
    static_assert(std::is_same_v<if_else_t<false, int, double>, double>);
    static_assert(std::is_same_v<if_else_t<false, double, std::uint64_t>, std::uint64_t>);

    static_assert(std::is_same_v<if_else_t<true, std::vector<std::uint64_t>, std::string>, std::vector<std::uint64_t>>);
    static_assert(std::is_same_v<if_else_t<false, std::vector<int>, std::string>, std::string>);

    using A = if_else<false, int, double>::type;
    static_assert(std::is_same_v<A, double>);

    using B = if_else<true, int, double>::type;
    static_assert(std::is_same_v<B, int>);

    static_assert(std::is_same_v<if_else_t<false, int, double>, double>);
    static_assert(std::is_same_v<if_else_t<true, int, double>, int>);

    std::cout << "if_else: ALL TESTS PASSED! \n";
}