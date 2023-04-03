#include "Solution034.h"

bool Solution034::isBoomerang(std::vector<std::vector<int>>& points)
{
   std::vector<int> a{ points[1][0] - points[0][0], points[1][1] - points[0][1] },
      b{ points[2][0] - points[0][0], points[2][1] - points[0][1] };
   return abs(a[0] * b[1] - a[1] * b[0]) > 0;
}
