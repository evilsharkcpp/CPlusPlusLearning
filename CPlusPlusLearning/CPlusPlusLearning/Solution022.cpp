#include "Solution022.h"

int Solution022::minTimeToVisitAllPoints(std::vector<std::vector<int>>& points)
{
   auto totalTime{ 0 };
   for (int i{ 1 }; i < points.size(); i++)
   {
      auto dx{ points[i][0] - points[i - 1][0] },
         dy{ points[i][1] - points[i - 1][1] };
      totalTime += std::max(abs(dx), abs(dy));
   }
   return totalTime;
}
