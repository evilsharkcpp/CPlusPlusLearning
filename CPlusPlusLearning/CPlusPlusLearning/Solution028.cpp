#include "Solution028.hpp"
#include <algorithm>

std::vector<std::vector<int>> Solution028::kClosest(std::vector<std::vector<int>>& points, int k)
{
   sort(points.begin(), points.end(),
      [](std::vector<int>& p, std::vector<int>& q)
      {
         return pow(p[0], 2) + pow(p[1], 2) < pow(q[0], 2) + pow(q[1], 2);
      });
   return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
}
