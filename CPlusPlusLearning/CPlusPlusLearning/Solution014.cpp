#include "Solution014.hpp"

int Solution014::searchInsert(std::vector<int>& nums, int target)
{
   if (target <= nums.front()) return 0;
   if (target > nums.back()) return nums.size();
   int startIndex{}, endIndex{ (int)nums.size() - 1 }, middleIndex{};
   while (startIndex < endIndex)
   {
      middleIndex = (endIndex + startIndex) / 2;
      if (nums[middleIndex] < target && nums[middleIndex + 1] >= target)
         return middleIndex + 1;
      if (nums[middleIndex] >= target)
         endIndex = middleIndex;
      else
         startIndex = middleIndex;
   }
   return -1;
}
