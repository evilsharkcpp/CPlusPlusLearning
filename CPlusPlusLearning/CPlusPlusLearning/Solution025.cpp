#include "Solution025.hpp"

int Solution025::removeElement(std::vector<int>& nums, int val)
{
   int i{};
   for (auto& num : nums)
      if (num != val)
      {
         nums[i] = num;
         i++;
      }
   return i;
}
