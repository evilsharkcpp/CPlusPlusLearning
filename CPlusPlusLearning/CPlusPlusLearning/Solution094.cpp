#include "Solution094.hpp"
#include <vector>

bool Solution094::buddyStrings(std::string s, std::string goal) {
    if(s.size() != goal.size()) {
        return false;
    }

    std::vector<int> indexes{};
    std::vector<int> letters(26);
    for(size_t i{}; i < s.length(); ++i) {
        ++letters[s[i] - 'a'];
        if(s[i] != goal[i]) {
            indexes.push_back(i);
        }
    }
    
    auto pr { std::max_element(std::begin(letters), std::end(letters)) };
    if(indexes.size() == 2 && goal[indexes[0]] == s[indexes[1]] && 
       goal[indexes[1]] == s[indexes[0]]) {
        return true;
    }
    
    if(*pr > 1 && indexes.size() == 0) {
        return true;
    }
    
    return false;
}