#include "Solution018.hpp"
#include <utility>

int Solution018::computeArea(int xBottomFirst, int yBottomFirst, int xTopFirst, int yTopFirst,
   int xBottomSecond, int yBottomSecond, int xTopSecond, int yTopSecond)
{
   int xOverlap{ std::min(xTopFirst, xTopSecond) - std::max(xBottomFirst, xBottomSecond) },
      yOverlap{ std::min(yTopFirst, yTopSecond) - std::max(yBottomFirst, yBottomSecond) },
      overlapArea{};

   if (xOverlap > 0 && yOverlap > 0)
      overlapArea = xOverlap * yOverlap;
   return (xTopFirst - xBottomFirst) * (yTopFirst - yBottomFirst) +
      (xTopSecond - xBottomSecond) * (yTopSecond - yBottomSecond) - overlapArea;
}
