#include "has_reserve.h"

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <deque>
#include <list>

void test_dsa() {
    static_assert(HasReserve<std::vector<int>>);
    static_assert(HasReserve<std::string>);
    static_assert(!HasReserve<std::deque<int>>);
    static_assert(!HasReserve<std::list<int>>);
}

void test_vector() {
    std::vector<int> nums;
    constexpr std::size_t size = 11;
    UniversalReserve(nums, size);
    assert(nums.capacity() >= size);
}

void test_string() {
    std::string name;
    constexpr std::size_t size = 13;
    UniversalReserve(name, size);
    assert(name.capacity() >= size);
}

void test_deque() {
    std::deque<int> deq;
    for (int i = 0; i < 10; ++i) deq.push_back(i);
    std::size_t size = deq.size();
    UniversalReserve(deq, size);
    assert(deq.size() == size);
}


int main() {
    test_dsa();
    test_vector();
    test_string();
    test_deque();
    std::cout << "has_reserve: ALL TESTS PASSED! \n";
}