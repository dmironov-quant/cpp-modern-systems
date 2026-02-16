#include "enable_if.h"
#include <cassert>

int main() {
    {
        Vector vec(5, 1);
        assert(vec.ctor_used() == Vector<int>::Ctor::Fill);
    }

    {
        std::vector<int> a{1,2,3};
        Vector<int> vec(a.begin(), a.end());
        assert(vec.ctor_used() == Vector<int>::Ctor::Range);
    }

    std::cout << "enable_if: ALL TESTS PASSED! \n";
}