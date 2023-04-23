#include "Solution033.hpp"

std::vector<std::vector<int>> Solution033::permute(std::vector<int>& nums)
{
   if (nums.size() == 1)
      return { nums };
   std::vector<std::vector<int>> result{};
   for (auto& num : nums)
   {
      std::swap(num, nums.front());
      auto out{ std::vector<int>(nums.begin() + 1, nums.end()) };
      auto comb{ permute(out) };
      std::swap(num, nums.front());
      for (auto& item : comb)
      {
         item.insert(item.begin(), num);
         result.push_back(item);
      }

   }
   return result;
}
