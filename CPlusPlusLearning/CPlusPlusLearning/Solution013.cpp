#include "Solution013.h"

int Solution013::search(std::vector<int>& nums, int target)
{
   int start = 0;
   int end = nums.size() - 1;
   int middle = 0;
   while (start <= end)
   {
      middle = start + (end - start) / 2;
      if (nums[middle] == target)
         return middle;
      if (nums[start] <= nums[middle])
      {
         if (target >= nums[start] && target < nums[middle])
            end = middle - 1;
         else
            start = middle + 1;
      }
      else
      {
         if (target <= nums[end] && target > nums[middle])
            start = middle + 1;
         else
            end = middle - 1;
      }
   }
   return -1;
}
