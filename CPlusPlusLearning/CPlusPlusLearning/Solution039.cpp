#include "Solution039.hpp"

std::vector<int> Solution039::plusOne(std::vector<int>& digits)
{
   auto result{ std::vector<int>(digits) };
   for (auto it{ result.rbegin() }; it != result.rend(); it++)
      if (*it == 9)
         *it = 0;
      else
      {
         *it += 1;
         break;
      }
   if (result.front() == 0)
      result.insert(result.begin(), 1);
   return result;
}
