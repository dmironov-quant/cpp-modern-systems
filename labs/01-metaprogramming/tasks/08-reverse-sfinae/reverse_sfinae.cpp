#include "reverse_sfinae.h"

#include <cassert>

int main() {
    {
        std::vector<int> before{1,2,3};
        std::vector<int> after{3,2,1};
        Reverse(before);
        assert(before == after);
    }

    {
        std::set<int> before{1,4,2};
        std::set<int> after = before;
        Reverse(before);
        assert(before == after);
    }

    {
        std::string before{"abcd"};
        std::string after = {"dcba"};
        Reverse(before);
        assert(before == after);
    }
}