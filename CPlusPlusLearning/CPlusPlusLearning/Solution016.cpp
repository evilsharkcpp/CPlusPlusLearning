#include "Solution016.h"

int Solution016::projectionArea(std::vector<std::vector<int>>& grid)
{
   int xyArea{};
   std::vector<int> xzProjection{}, yzProjection{};
   for (auto& column : grid)
   {
      if (yzProjection.size() < column.size())
         yzProjection.resize(column.size(), 0);
      int xzMaxArea{};
      int i{ 0 };
      for (auto& row : column)
      {
         if (row != 0) xyArea++;
         yzProjection[i] = std::max(row, yzProjection[i]);
         xzMaxArea = std::max(xzMaxArea, row);
         i++;
      }
      xzProjection.push_back(xzMaxArea);
   }
   int totalArea{ xyArea };
   for (auto& area : xzProjection)
      totalArea += area;
   for (auto& area : yzProjection)
      totalArea += area;
   return totalArea;
}

int Solution016::projectionAreaOptimized(std::vector<std::vector<int>>& grid)
{
   int totalArea{};
   for (int i{}; i < grid.size(); i++)
   {
      int xzMax{}, yzMax{};
      for (int j{}; j < grid[i].size(); j++)
      {
         if (grid[i][j] > 0)
            totalArea++;
         xzMax = std::max(xzMax, grid[i][j]);
         yzMax = std::max(yzMax, grid[j][i]);
      }
      totalArea += xzMax + yzMax;
   }
   return totalArea;
}
