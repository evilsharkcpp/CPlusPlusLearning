#include "Solution089.hpp"
#include <unordered_map>
#include<unordered_set>

bool Solution089::uniqueOccurrences(std::vector<int> &arr) {
    
    std::unordered_map<int, int> occurrences{};
    for(const int& num : arr) {
        if(occurrences.count(num) > 0) {
            ++occurrences[num];
        } else {
            occurrences[num] = 1;
        }
    }
    
    std::unordered_set<int> result{};
    for(const auto& p : occurrences) {
        result.emplace(p.second);
    }
    
    return result.size() == occurrences.size();
}