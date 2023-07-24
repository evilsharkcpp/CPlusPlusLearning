#include "Solution099.hpp"

#include<unordered_map>

int Solution099::countQuadruplets(std::vector<int> &nums) {
    int result{};
    std::unordered_map<int, int> mp;
    size_t n { nums.size() };
    
    for(int i { 1 };i < n; ++i) {
        for(int j{};j < i; ++j) {
            mp[nums[i] + nums[j]]++;
        }
        
        for(int k{ i + 2 }; k < n; ++k) {
            result += mp[nums[k] - nums[i + 1]];
        }
    }

    return result; 
}