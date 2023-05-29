#include "Solution079.hpp"

int Solution079::countGoodRectangles(std::vector<std::vector<int>> &rectangles) {
    int maxLength{};
    int maxCount{};

    for(const auto& rectangle : rectangles) {
       int candidate { std::min(rectangle[0], rectangle[1]) };
       
       if(candidate == maxLength) {
           ++maxCount;
       } else if (candidate > maxLength) {
           maxLength = candidate;
           maxCount = 1;
       }
    }

    return maxCount;
}