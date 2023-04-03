#include "Solution050.h"

bool Solution050::isPalindrome(std::string s)
{
   std::string str{};
   for (const auto& ch : s)
   {
      if (ch >= 'A' && ch <= 'Z')
         str += ch - ('Z' - 'z');
      if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
         str += ch;
   }

   auto len{ str.length() };
   for (size_t i{}; i < len / 2; i++)
      if (str[i] != str[len - 1 - i])
         return false;
   return true;
}
