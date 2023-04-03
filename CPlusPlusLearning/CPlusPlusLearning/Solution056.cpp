#include "Solution056.h"
#include <unordered_map>

int Solution056::majorityElementWithHashMap(std::vector<int>& nums)
{
   std::unordered_map<int, int> seen{};
   for (const auto& num : nums)
      seen[num]++;

   std::pair<int, int> best{ 0, std::numeric_limits<int>::min() };
   for (const auto& count : seen)
      if (count.second > best.second)
         best = count;
   return best.first;
}

int Solution056::majorityElement(std::vector<int>& nums)
{
   int candidate{}, count{};
   for (const auto& num : nums)
   {
      if (count == 0)
         candidate = num;
      count += candidate == num ? 1 : -1;
   }
   return candidate;
}
