#include "Solution041.h"
#include <set>
#include <algorithm>

int Solution041::countLatticePoints(const std::vector<std::vector<int>>& circles)
{
   auto isInside
   {
       [](const std::vector<int>& circle, int x, int y)
       {
           return pow(x - circle[0], 2) + pow(y - circle[1], 2) <= pow(circle[2], 2);
       }
   };
   std::set<std::pair<int, int>> points{};
   std::set<std::vector<int>> seen{};
   for (const auto& circle : circles)
   {
      if (seen.count(circle))
         continue;
      seen.insert(circle);
      int xBottom{ circle[0] - circle[2] },
         yBottom{ circle[1] - circle[2] },
         xTop{ circle[0] + circle[2] },
         yTop{ circle[1] + circle[2] };
      for (auto x{ xBottom }; x <= xTop; x++)
         for (auto y{ yBottom }; y <= yTop; y++)
            if (isInside(circle, x, y))
               points.insert({ x,y });
   }
   return points.size();
}

int Solution041::countLatticePointsOptimized(const std::vector<std::vector<int>>& circles)
{
   int xBottom{ std::numeric_limits<int>::max() },
      yBottom{ std::numeric_limits<int>::max() },
      xTop{ std::numeric_limits<int>::min() },
      yTop{ std::numeric_limits<int>::min() };
   for (const auto& circle : circles)
   {
      xBottom = std::min(xBottom, circle[0] - circle[2]);
      yBottom = std::min(yBottom, circle[1] - circle[2]);
      xTop = std::max(xTop, circle[0] + circle[2]);
      yTop = std::max(yTop, circle[1] + circle[2]);
   }
   int counter{};
   for (auto x{ xBottom }; x <= xTop; x++)
      for (auto y{ yBottom }; y <= yTop; y++)
         if (any_of(circles.begin(), circles.end(),
            [&x, &y](const std::vector<int>& circle)
            {
               return pow(x - circle[0], 2) + pow(y - circle[1], 2) <=
               pow(circle[2], 2);
            }))
            counter++;
            return counter;
}
