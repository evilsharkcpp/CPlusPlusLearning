#include "Solution048.hpp"

std::vector<std::vector<int>> Solution048::generate(int numRows)
{
   std::vector<std::vector<int>> result{};
   result.reserve(numRows);
   result.push_back({ 1 });
   for (size_t i{ 1 }; i < numRows; i++)
   {
      std::vector<int> rowNew{};
      rowNew.reserve(i + 1);
      rowNew.push_back(1);
      for (size_t j{ 1 }; j < result[i - 1].size(); j++)
         rowNew.push_back(result[i - 1][j] + result[i - 1][j - 1]);
      rowNew.push_back(1);
      result.push_back(rowNew);
   }
   return result;
}
