#include "Solution068.hpp"

bool Solution068::canJump(std::vector<int> &nums) {
    
    int n { static_cast<int>(nums.size())};
    int x{ n - 1 };
    bool canJump{};

    for(int i{ n - 1 }; i >= 0; --i) {
        if(i + nums[i] >= x) {
            canJump = true;
            x = i;
        }
        else {
            canJump = false;
        }
    }

    return canJump;
}