#include "Solution064.hpp"

bool Solution064::containsNearbyDuplicate(std::vector<int> &nums, int k){
    size_t size{ nums.size() };
    std::unordered_map<int, size_t> numsIndexes{};
    
    for(size_t i{}; i < size; ++i) {
        if(numsIndexes.count(nums[i]) > 0) {
            if(abs(static_cast<int>(i) - static_cast<int>(numsIndexes[nums[i]])) <= k) {
                return true;
            }
        }
        numsIndexes[nums[i]] = i;
    }

    return false;
}