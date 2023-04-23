#include "Solution003.hpp"

std::string Solution003::longestCommonPrefix(std::vector<std::string>& strs)
{
   if (strs.size() == 1)
      return strs[0];
   std::string currentStr = strs[0];
   for (const auto& str : strs)
   {
      std::string tmp;
      for (int i = 0; i < str.length() && i < currentStr.length(); i++)
         if (str[i] == currentStr[i])
            tmp += str[i];
         else
            break;
      currentStr = tmp;
   }
   return currentStr;
}
