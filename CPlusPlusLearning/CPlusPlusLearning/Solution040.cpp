#include "Solution040.hpp"

int Solution040::surfaceArea(const std::vector<std::vector<int>>& grid)
{
   int areaTotal{};
   size_t size{ grid.size() };
   for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
      {
         if (grid[i][j] != 0)
            areaTotal += grid[i][j] * 4 + 2;
         if (i != 0)
            areaTotal -= std::min(grid[i][j], grid[i - 1][j]) * 2;
         if (j != 0)
            areaTotal -= std::min(grid[i][j], grid[i][j - 1]) * 2;
      }
   return areaTotal;
}
