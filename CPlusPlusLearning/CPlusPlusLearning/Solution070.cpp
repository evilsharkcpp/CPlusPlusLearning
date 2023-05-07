#include "Solution070.hpp"
#include <algorithm>

int Solution070::findContentChildren(std::vector<int> &g, std::vector<int> &s){
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    size_t maxCount{};
    size_t n {g.size()}, m {s.size()};
    for(size_t i{}, j{}; i < n && j < m; ++j) {
        if(s[j] >= g[i]) {
            ++maxCount;
            ++i;
        }
    }
    return maxCount;
}