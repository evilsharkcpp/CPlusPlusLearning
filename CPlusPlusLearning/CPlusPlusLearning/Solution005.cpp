#include "Solution005.h"
#include <set>
#include <algorithm>

std::vector<std::vector<int>> Solution005::threeSum(std::vector<int>& nums)
{
   std::vector<std::vector<int>> result{};
   std::set<std::vector<int>> s{};
   std::sort(nums.begin(), nums.end());
   for (int i{ 0 }; i < nums.size() - 2 && nums[i] <= 0; i++)
   {
      int left = i + 1;
      int right = nums.size() - 1;
      while (right > left)
      {
         int sum = nums[i] + nums[left] + nums[right];
         if (sum == 0)
         {
            s.insert({ nums[i], nums[left], nums[right] });
            //ignore duplicates of nums[left]
            while (left < right && nums[left] == nums[left + 1]) left++;
            //ignore duplicates of nums[right]
            while (left < right && nums[right] == nums[right - 1]) right--;
            left++;
            right--;
         }
         else
            if (sum > 0)
               right--;
            else
               left++;
         while (i < nums.size() - 2 && nums[i] == nums[i + 1]) i++;
      }
   }
   result.assign(s.begin(), s.end());
   return result;
}
