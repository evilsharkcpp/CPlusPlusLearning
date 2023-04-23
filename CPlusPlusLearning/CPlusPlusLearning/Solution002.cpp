#include "Solution002.hpp"

int Solution002::maxArea(std::vector<int>& height)
{
   int maxSquare = 0;
   int left = 0;
   int right = height.size() - 1;
   while (left < right)
   {
      int h = std::min(height[left], height[right]);
      maxSquare = std::max(maxSquare, h * (right - left));
      if (height[left] < height[right])
         left++;
      else
         right--;
   }
   return maxSquare;
}
