#include "Solution071.hpp"

int Solution071::maxScore(std::vector<int> &nums) {
    sort(nums.begin(), nums.end(), std::greater<int>());
    int maxScope{};
    long long scope{};
    for(const int& num : nums) {
        scope += num;
        if(scope > 0) {
            ++maxScope;
        }
    }
    return maxScope;
}