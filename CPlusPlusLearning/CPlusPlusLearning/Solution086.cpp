#include "Solution086.hpp"

bool Solution086::arrayStringsAreEqual(std::vector<std::string> &word1,
 std::vector<std::string> &word2) {
    
    std::string word1Combined{};
    for (const std::string& s : word1) {
        word1Combined += s;
    }
    
    std::string word2Combined{};
    for (const std::string& s : word2) {
        word2Combined += s;
    }
    
    return word1Combined == word2Combined;
}