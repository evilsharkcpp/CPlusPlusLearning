#include "Solution098.hpp"

#include <limits>
#include <algorithm>

int Solution098::threeSumClosest(std::vector<int> &nums, int target)  {
    size_t n{ nums.size() };
    std::sort(nums.begin(), nums.end());
    int minRange{ std::numeric_limits<int>::max() }, result{};
    for(size_t i{}; i < n; ++i) {
        int left { static_cast<int>(i) + 1 };
        int right { static_cast<int>(n) - 1 };
        while(left < right) {
            int sum { nums[i] + nums[left] + nums[right] };
            int range { abs(sum - target) };
            
            if(range == 0) {
                return target;
            } else if(sum < target) {
                ++left;
            } else {
                --right;
            }

            if(range < minRange) {
                minRange = range;
                result = sum;
            }
        }
    }

    return result;
}