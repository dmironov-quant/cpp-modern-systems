#pragma once
#include <iostream>
#include <vector>
#include <type_traits>
#include <cstddef>

template <bool Val>
struct enable_if;

template <>
struct enable_if<true> { using type = void; };

template <typename T>
class Vector {
public:
    enum class Ctor { Fill, Range };

    Vector(T value, std::size_t size)
        : vec{std::vector<T>(size, value)}
        , ctor_{Ctor::Fill}
    {}

    template <typename Iterator, typename Dummy = enable_if<!std::is_integral_v<Iterator>>::type>
    Vector(Iterator start, Iterator end)
        : vec(start, end)
        , ctor_{Ctor::Range}
    {}

    Ctor ctor_used() const { return ctor_; }

private:
    std::vector<T> vec;
    Ctor ctor_;
};

