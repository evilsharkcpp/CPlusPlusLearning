#include "Solution036.hpp"
#include <functional>

int Solution036::mirrorReflection(int p, int q)
{
   std::function<int(int, int)> gcd
   {
      [&](int a, int b)
      {
         return b == 0 ? a : gcd(b, a % b);
      }
   };
   int m{ q / gcd(p, q) },
      n{ p / gcd(p, q) };
   switch (m % 2)
   {
   case 0:
      return n % 2 == 1 ? 0 : -1;
      break;
   case 1:
      return n % 2 == 1 ? 1 : 2;
      break;
   }
   return -1;
}
