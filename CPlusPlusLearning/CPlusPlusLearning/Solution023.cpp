#include "Solution023.hpp"
#include <unordered_map>

int Solution023::maxPoints(std::vector<std::vector<int>>& points)
{
   if (points.size() == 1)
      return 1;

   int bestCount{};
   for (auto& p1 : points)
   {
      std::unordered_map<double, int> looksup{};
      for (auto& p2 : points)
      {
         auto dx{ p2[0] - p1[0] },
            dy{ p2[1] - p1[1] };
         if (dx == 0 && dy == 0)
            continue;
         auto k{ atan((double)dy / dx) };
         looksup[k]++;
      }
      for (auto& pair : looksup)
         bestCount = std::max(bestCount, pair.second + 1);
   }
   return bestCount;
}
