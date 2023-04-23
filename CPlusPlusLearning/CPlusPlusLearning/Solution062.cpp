#include "Solution062.hpp"
#include <vector>

std::string Solution062::intToRomanWithTable(int num)
{
   std::vector<std::vector<std::string>> numbers
   {
       { "", "M", "MM", "MMM" },
       { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
       { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
       { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
   };
   return numbers[0][num / 1000] + numbers[1][num / 100 % 10] +
      numbers[2][num / 10 % 10] + numbers[3][num % 10];
}

std::string Solution062::intToRoman(int num)
{
   std::string result{};
   std::vector<std::pair<int, std::string>> storeIntRoman{ {1000, "M"}, {900, "CM"},
      {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
      {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} };
   for (int i{}; i < storeIntRoman.size(); i++)
      while (num >= storeIntRoman[i].first)
      {
         result += storeIntRoman[i].second;
         num -= storeIntRoman[i].first;
      }
   return result;
}
