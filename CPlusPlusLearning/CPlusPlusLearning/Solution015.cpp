#include "Solution015.h"

bool Solution015::isPalindrome(int x)
{
   if (x < 0 || (x % 10 == 0 && x != 0)) return false;
   int reverseX{};
   while (x > reverseX)
   {
      reverseX = reverseX * 10 + x % 10;
      x /= 10;
   }
   return x == reverseX || x == reverseX / 10;
}
