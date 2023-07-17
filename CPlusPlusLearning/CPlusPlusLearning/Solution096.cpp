#include "Solution096.hpp"

int Solution096::missingNumber(std::vector<int> &nums) {
    int sum{}, n{static_cast<int>(nums.size())};
    for(size_t i{}; i < n; ++i) {
        sum += nums[i];
    }
    
    return n * (n + 1) / 2 - sum;
}