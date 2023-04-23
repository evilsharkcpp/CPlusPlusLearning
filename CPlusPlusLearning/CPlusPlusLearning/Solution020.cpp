#include "Solution020.hpp"

bool Solution020::validSquare(std::vector<int>& p1, std::vector<int>& p2,
   std::vector<int>& p3, std::vector<int>& p4)
{
   auto computeDist
   {
       [](std::vector<int>& p1, std::vector<int>& p2)
       {
           return pow((p2[0] - p1[0]), 2) + pow((p2[1] - p1[1]), 2);
       }
   };
   auto isSquare
   {
       [=](std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4)
       {
           return computeDist(p1, p2) > 0 && computeDist(p1, p3) > 0 && computeDist(p1, p4) > 0 &&
           computeDist(p1, p2) == computeDist(p2, p3) && computeDist(p2, p3) == computeDist(p3, p4) &&
           computeDist(p3, p4) == computeDist(p4, p1) && computeDist(p1, p3) == computeDist(p2, p4);
       }
   };
   return isSquare(p1, p2, p3, p4) || isSquare(p1, p3, p2, p4) || isSquare(p1, p2, p4, p3);
}
