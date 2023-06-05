#include "Solution081.hpp"

#include<algorithm>
#include<unordered_map>

std::vector<std::string> Solution081::findRelativeRanks(std::vector<int> &score) {
    std::vector<int> sortedScore{ score };
    std::sort(sortedScore.begin(), sortedScore.end(), std::greater<int>());

    std::unordered_map<int, std::string>map{};
    
    size_t n { score.size() };
    for(size_t i{}; i < n; ++i) {
        switch(i) {
            case 0:
                map[sortedScore[i]] = "Gold Medal";
            break;
            case 1:
                map[sortedScore[i]] = "Silver Medal";
            break;
            case 2:
                map[sortedScore[i]] = "Bronze Medal";
            break;
            default:
                map[sortedScore[i]] = std::to_string(i + 1);
            break;
        }
    }

    std::vector<std::string> result{};
    for(size_t i{}; i < n; ++i) {
        if(map.find(score[i]) != map.end()){
            result.push_back(map[score[i]]);
        }
    }
    
    return result; 
}