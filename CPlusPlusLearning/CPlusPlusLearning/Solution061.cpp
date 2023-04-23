#include "Solution061.hpp"
#include <vector>

std::string Solution061::convert(std::string s, int numRows)
{
   std::vector<std::string> sRows(numRows, "");
   int rowIndex{};
   int direction{};

   for (const auto& ch : s)
   {
      sRows[rowIndex] += ch;
      direction = numRows == 1 ? 0 : rowIndex == 0 ?
         1 : rowIndex == numRows - 1 ? -1 : direction;
      rowIndex += direction;
   }

   std::string result{};
   for (const auto& row : sRows)
      result += row;

   return result;
}
