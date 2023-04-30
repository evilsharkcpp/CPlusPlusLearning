#include "Solution066.hpp"

int Solution066::longestPalindrome(std::string s) {
    std::unordered_map<char, int> lettersCount{};
    lettersCount.reserve(128);
    int length{};
    
    for(const char& ch : s) {
        if(++lettersCount[ch] == 2){
            length += 2;
            lettersCount[ch] = 0;
        }
    }

    return length == s.length() ? length : length + 1;
}