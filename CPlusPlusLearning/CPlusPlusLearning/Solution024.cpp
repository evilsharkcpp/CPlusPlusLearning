#include "Solution024.hpp"

bool Solution024::checkStraightLine(std::vector<std::vector<int>>& coordinates)
{
   auto leftPoint{ coordinates.front() },
      rightPoint{ coordinates.back() };

   auto dx{ (rightPoint[0] - leftPoint[0]) },
      dy{ (rightPoint[1] - leftPoint[1]) };

   for (auto& point : coordinates)
   {
      auto leftPart{ (double)(point[0] - leftPoint[0]) / dx },
         rightPart{ (double)(point[1] - leftPoint[1]) / dy };
      bool isBeenOnAxisX{ ((rightPoint[0] - leftPoint[0]) == 0 && point[0] == leftPoint[0]) },
         isBeenOnAxisY{ ((rightPoint[1] - leftPoint[1]) == 0 && point[1] == leftPoint[1]) };
      if ((!isBeenOnAxisX && !isBeenOnAxisY) && leftPart != rightPart)
         return false;
   }
   return true;
}

bool Solution024::checkStraightLineAnother(std::vector<std::vector<int>>& coordinates)
{
   auto leftPoint{ coordinates.front() },
      rightPoint{ coordinates.back() };

   auto dx{ (rightPoint[0] - leftPoint[0]) },
      dy{ (rightPoint[1] - leftPoint[1]) };

   for (auto& point : coordinates)
   {
      auto leftPart{ (double)(point[0] - leftPoint[0]) * dy },
         rightPart{ (double)(point[1] - leftPoint[1]) * dx };
      if (leftPart != rightPart)
         return false;
   }
   return true;
}
