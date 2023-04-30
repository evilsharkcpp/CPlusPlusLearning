#include "Solution065.hpp"

bool Solution065::containsDuplicate(std::vector<int> &nums) {
    std::unordered_map<int, int> numsCount{};
    numsCount.reserve(nums.size());

    for(const int& num : nums) {
        if(++numsCount[num] == 2) {
            return true;
        }
    }

    return false;
}
