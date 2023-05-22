#include "Solution075.hpp"

int Solution075::differenceOfSum(std::vector<int> &nums) {
    
    int elementSum{};
    int digitSum{};

    for(auto& num : nums) {
        elementSum += num;
        while(num > 0) {
            digitSum += num % 10;
            num /= 10;
        }
    }

    return abs(elementSum - digitSum);
}