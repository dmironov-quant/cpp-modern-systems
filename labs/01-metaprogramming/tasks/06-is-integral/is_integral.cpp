#include "is_integral.h"
#include <iostream>

int main() {
    static_assert(is_integral_v<bool>);
    static_assert(is_integral_v<char>);
    static_assert(!is_integral_v<double>);
    static_assert(is_integral_v<int>);
    std::cout << "is_integral: ALL TESTS PASSED! \n";
}