#include "addable.h"

#include <iostream>
#include <cassert>
#include <numeric>
#include <string>

void test_int() {
    std::vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 1);
    int sum_all = SumAll(vec);
    int acc = std::accumulate(vec.begin(), vec.end(), 0);
    assert(sum_all == acc);
}

void test_string() {
    std::vector<std::string> vec(2);
    vec.emplace_back("a");
    vec.emplace_back("b");
    std::string sum_all = SumAll(vec);
    std::string res = "ab";
    assert(sum_all == res);
}

struct Element {
    int element;
};

// void test_custom_assert_error() {
//     std::vector<Element> vec;
//     int idx = 0;
//     for (auto it = begin(vec); it != begin(vec) + 5; ++it) it->element = idx++;
//     auto sum_all = SumAll(vec);
// }

struct Custom {
    int element;
    Custom operator+(const Custom& other) const {
        return Custom{this->element + other.element};
    }
    bool operator==(const Custom& other) const {
        return this->element == other.element;
    }
};

void test_custom_ok() {
    std::vector<Custom> vec{{1}, {2}};
    auto sum_all = SumAll(vec);
    Custom res{3};
    assert(res == sum_all);
}

int main() {
    test_int();
    test_string();
    // test_custom_assert_error(); // static_assert "SumAll<T> requires Addable<T> : expression (a + b) must be valid and convertible to T"
    test_custom_ok();
    std::cout << "addable: ALL TESTS PASSED! \n";
}