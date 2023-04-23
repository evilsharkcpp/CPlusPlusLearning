#include "Solution053.hpp"
#include <cmath>

bool Solution053::isHappy(int n)
{
   auto getNumber
   {
       [](int n)
       {
           int result{};
           while (n > 0)
           {
               result += pow(n % 10, 2);
               n /= 10;
           }
           return result;
       }
   };
   auto fast{ getNumber(n) }, slow{ n };
   while (fast != 1 && slow != fast)
   {
      fast = getNumber(getNumber(fast));
      slow = getNumber(slow);
   }
   return fast == 1;
}
