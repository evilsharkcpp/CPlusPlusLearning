#include "Solution076.hpp"
#include <unordered_map>
#include <unordered_set>
#include <array>

bool Solution076::isPathCrossing(std::string path) {
    std::unordered_map<int, std::unordered_set<int>> hash{{0, std::unordered_set<int>{0}}};
    std::array<int, 2> current_pos {0, 0}; 

    for(const auto& p : path) {
        switch(p) {
            case 'N':
                ++current_pos[1];
            break;
            case 'S':
                --current_pos[1];
            break;
            case 'E':
                ++current_pos[0];
            break;
            case 'W':
                --current_pos[0];
            break;
        }

        if (hash.find(current_pos[0]) != hash.end()) {
            if(hash[current_pos[0]].find(current_pos[1]) != hash[current_pos[0]].end()) {
                return true;
            } else {
                hash[current_pos[0]].insert(current_pos[1]);
            }
        } else {
            hash.insert({current_pos[0], std::unordered_set<int>{current_pos[1]}});
        }
    }
    
    return false;
}