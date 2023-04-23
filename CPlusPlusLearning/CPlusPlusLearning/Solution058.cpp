#include "Solution058.hpp"

int Solution058::search(std::vector<int>& nums, int target)
{
   int startIndex{}, endIndex{ (int)nums.size() - 1 },
      middleIndex{};

   while (startIndex <= endIndex)
   {
      middleIndex = (startIndex + endIndex) / 2;
      if (nums[middleIndex] == target)
         return middleIndex;
      if (nums[middleIndex] > target)
         endIndex = middleIndex - 1;
      else
         startIndex = middleIndex + 1;
   }

   return -1;
}
