#include "Solution038.h"

std::string Solution038::addBinary(std::string a, std::string b)
{
   std::string result{};
   int carry{};
   int i{ (int)a.length() - 1 };
   int j{ (int)b.length() - 1 };

   while (i >= 0 || j >= 0 || carry)
   {
      if (i >= 0)
         carry += a[i--] - '0';
      if (j >= 0)
         carry += b[j--] - '0';
      result += carry % 2 + '0';
      carry /= 2;
   }
   reverse(result.begin(), result.end());
   return result;
}
