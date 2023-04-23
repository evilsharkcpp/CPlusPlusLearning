#include "Solution043.hpp"
#include <unordered_map>

int Solution043::singleNumber(std::vector<int>& nums)
{
   std::unordered_map<int, size_t> seen{};
   for (const auto& num : nums)
      seen[num]++;
   for (const auto& item : seen)
      if (item.second == 1)
         return item.first;
   return -1;
}

int Solution043::singleNumberBitwiseOr(std::vector<int>& nums)
{
   int candidate{};
   for (const auto& num : nums)
      candidate ^= num;
   return candidate;
}
