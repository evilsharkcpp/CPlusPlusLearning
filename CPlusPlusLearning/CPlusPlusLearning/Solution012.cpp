#include "Solution012.hpp"

int Solution012::strStr(std::string haystack, std::string needle)
{
   for (int i = 0; i < haystack.length(); i++)
   {
      bool isEqual = true;
      for (int k = 0; k < needle.length(); k++)
      {
         if (i + k >= haystack.length())
            return -1;
         if (haystack[i + k] != needle[k])
         {
            isEqual = false;
            break;
         }
      }
      if (isEqual)
         return i;
   }
   return -1;
}
