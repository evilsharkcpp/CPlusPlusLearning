#include "Solution095.hpp"

void Solution095::moveZeroes(std::vector<int> &nums) {
    for(size_t left{}, right{}; right < nums.size(); ++right) {
        if(nums[right] != 0) {
            std::swap(nums[left++], nums[right]);
        }
    }
}