#include "Solution085.hpp"

std::vector<std::string> Solution085::summaryRanges(std::vector<int> &nums) {

if(nums.size() == 0) {
    return {};
}

int start{nums[0]};
int end{nums[0]};
size_t n { nums.size() };
std::vector<std::string> result{};
auto getRange {
    [](int a, int b) {
        if(a != b) {
           return std::to_string(a) + "->" + std::to_string(b);
       } else {
           return std::to_string(a);
       }
    }
};

for(size_t i{ 1 }; i < n; ++i) {
   if(++end != nums[i]) {
       result.push_back(getRange(start, nums[i - 1]));
       start = nums[i];
       end = nums[i];
   }
}

result.push_back(getRange(start, end));

return result;
}