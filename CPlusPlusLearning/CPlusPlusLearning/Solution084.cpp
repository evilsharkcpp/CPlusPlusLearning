#include "Solution084.hpp"

char Solution084::findTheDifference(std::string s, std::string t) {
    long sSum{}, tSum{};
    
    for(const char& ch : s) {
        sSum += static_cast<long>(ch);
    }

    for(const char& ch : t) {
        tSum += static_cast<long>(ch);
    }

    return static_cast<char>(tSum - sSum);
}