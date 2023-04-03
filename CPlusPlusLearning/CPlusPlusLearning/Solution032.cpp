#include "Solution032.h"
#include <map>
#include <algorithm>

std::vector<std::vector<int>> Solution032::allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
{
   std::vector<std::vector<int>> result;
   std::multimap<int, std::vector<int>> dists;
   for (int row{}; row < rows; row++)
      for (int col{}; col < cols; col++)
         result.push_back({ row, col });
   sort(result.begin(), result.end(),
      [&](std::vector<int>& a, std::vector<int>& b)
      {
         return abs(rCenter - a[0]) + abs(cCenter - a[1]) <
         abs(rCenter - b[0]) + abs(cCenter - b[1]);
      });
   return result;
}
