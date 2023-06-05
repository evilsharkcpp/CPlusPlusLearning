#include "Solution082.hpp"

void Solution082::reverseString(std::vector<char> &s) {
    for(int left{}, right{static_cast<int>(s.size()) - 1};
        left <= right; ++left, --right) {
        std::swap(s[left], s[right]);
    }
}