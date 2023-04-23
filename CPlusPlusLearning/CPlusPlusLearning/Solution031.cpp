#include "Solution031.hpp"

double Solution031::largestTriangleArea(std::vector<std::vector<int>>& points)
{
   auto getSquare
   {
       [](std::vector<int> a, std::vector<int> b, std::vector<int> c)
       {
           std::vector<int> vFirst { b[0] - a[0], b[1] - a[1] },
                       vSecond { c[0] - a[0], c[1] - a[1] };
           return abs(1.0 / 2 * (vFirst[0] * vSecond[1] - vFirst[1] * vSecond[0]));
       }
   };
   double maxSquare{};
   for (int i{}; i < points.size() - 2; i++)
      for (int j{ i + 1 }; j < points.size() - 1; j++)
         for (int k{ j + 1 }; k < points.size(); k++)
            maxSquare = std::max(maxSquare, getSquare(points[i], points[j], points[k]));
   return maxSquare;
}
