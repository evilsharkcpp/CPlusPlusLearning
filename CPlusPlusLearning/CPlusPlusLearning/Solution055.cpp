#include "Solution055.h"

std::string Solution055::convertToTitle(int columnNumber)
{
   std::string result{};
   while (columnNumber-- > 0)
   {
      result.push_back(columnNumber % 26 + 'A');
      columnNumber /= 26;
   }
   reverse(result.begin(), result.end());
   return result;
}
