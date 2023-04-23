#include "Solution017.hpp"

bool Solution017::isRectangleOverlap(std::vector<int>& firstRect, std::vector<int>& secondRect)
{
   int xOverlap{ std::min(firstRect[2], secondRect[2]) - std::max(firstRect[0], secondRect[0]) },
      yOverlap{ std::min(firstRect[3], secondRect[3]) - std::max(firstRect[1], secondRect[1]) };
   return xOverlap > 0 && yOverlap > 0;
}
