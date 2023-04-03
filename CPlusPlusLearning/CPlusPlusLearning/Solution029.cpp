#include "Solution029.h"

int Solution029::lengthOfLastWord(std::string s)
{
   int length{};
   for (auto it{ s.rbegin() }; it != s.rend(); it++)
   {
      if (*it == ' ' && length > 0)
         break;
      if (*it == ' ')
         continue;
      length++;
   }
   return length;
}
