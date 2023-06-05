#include "Solution083.hpp"

bool Solution083::isSubsequence(std::string s, std::string t)   {
    size_t n{ s.size() };
    size_t m{ t.size() };
    
    size_t i{}, j{};
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            ++i;
        }
        ++j;
    }
    
    return i == n;
}