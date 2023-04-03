#include "Solution035.h"
#include <unordered_set>

int Solution035::maximumDetonation(std::vector<std::vector<int>>& bombs)
{
   auto isInside
   {
       [](std::vector<int>& bombDetonated, std::vector<int>& bomb)
       {
           return pow(bombDetonated[0] - bomb[0], 2) +
                  pow(bombDetonated[1] - bomb[1], 2) <=
                  pow(bombDetonated[2], 2);
       }
   };
   size_t detonatedMaxCount{};
   std::unordered_set<int> detonatedBombs{};
   for (size_t bombFirstIndex{}; bombFirstIndex < bombs.size(); bombFirstIndex++)
   {
      detonatedBombs.clear();
      detonatedBombs.emplace(bombFirstIndex);
      auto detonatedBomb{ detonatedBombs.begin() };
      while (detonatedBomb != detonatedBombs.end())
      {
         auto previousSize{ detonatedBombs.size() };
         for (size_t bombIndex{}; bombIndex < bombs.size(); bombIndex++)
            if (detonatedBombs.count(bombIndex) == 0 && isInside(bombs[*detonatedBomb], bombs[bombIndex]))
               detonatedBombs.emplace(bombIndex);
         if (previousSize == detonatedBombs.size())
            detonatedBomb++;
         else
            detonatedBomb = detonatedBombs.begin();
      }
      detonatedMaxCount = std::max(detonatedMaxCount, detonatedBombs.size());
   }
   return detonatedMaxCount;
}
