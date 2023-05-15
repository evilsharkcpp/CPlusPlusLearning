#include "Solution074.hpp"

std::vector<std::vector<int>> Solution074::findDifference(std::vector<int> &nums1,
std::vector<int> &nums2) {
        
    std::unordered_set<int> distinctNums1{};
    for(const auto& num : nums1) {
        distinctNums1.insert(num);
    }

    std::unordered_set<int> distinctNums2{};
    for(const auto& num : nums2) {
        distinctNums2.insert(num);
    }
    
    auto getSame {
        [](const std::unordered_set<int>& a, 
        std::unordered_set<int>& b) {
            std::vector<int> result{};
            for(const auto& num: a) {
                if(b.count(num) == 0) {
                    result.push_back(num);
                }
            }
            return result;
        }
    };

    return { getSame(distinctNums1, distinctNums2),
     getSame(distinctNums2, distinctNums1) };
}