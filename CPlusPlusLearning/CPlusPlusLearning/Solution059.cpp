#include "Solution059.h"
#include <algorithm>

int Solution059::numRescueBoats(std::vector<int>& people, int limit)
{
   sort(people.begin(), people.end());

   int boatsCount{}, left{}, right{ (int)people.size() - 1 };

   while (left <= right)
   {
      boatsCount++;
      if (people[left] + people[right] <= limit)
         left++;
      right--;
   }

   return boatsCount;
}
