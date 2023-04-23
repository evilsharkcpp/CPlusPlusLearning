#include "Solution019.hpp"
#include <utility>

bool Solution019::checkOverlap(int radius, int xCenter, int yCenter, 
   int xBottom, int yBottom, int xTop, int yTop)
{
   auto isInside
   {
       [=](int xPoint, int yPoint)
       {
           return (xPoint - xCenter) * (xPoint - xCenter) +
                  (yPoint - yCenter) * (yPoint - yCenter) <= radius * radius;
       }
   };
   return isInside(std::max(xBottom, std::min(xCenter, xTop)),
      std::max(yBottom, std::min(yCenter, yTop)));
}
