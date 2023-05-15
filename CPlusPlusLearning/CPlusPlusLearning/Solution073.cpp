#include "Solution073.hpp"

int Solution073::arraySign(std::vector<int> &nums) {
    int sign{ 1 };

    for(const auto& num : nums) {
        if (num == 0) {
            return 0;
        } else if (num < 0) {
            sign *= -1;
        }
    }

    return sign;
}