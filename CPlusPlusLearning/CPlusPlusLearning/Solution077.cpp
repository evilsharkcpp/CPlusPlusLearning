#include "Solution077.hpp"

std::string Solution077::mergeAlternately(std::string word1, std::string word2) {
    size_t size{std::min(word1.length(), word2.length())};

    std::string result{};
    for(size_t i{}; i < size; ++i) {
        result += word1[i] + word2[i];
    }

    std::string append {word1.length() > word2.length() ? word1 : word2 };
    size_t maxSize { std::max(word1.length(), word2.length()) };

    for(size_t i{ size }; i < maxSize; ++i) {
        result += append[i];
    }

    return result;
}