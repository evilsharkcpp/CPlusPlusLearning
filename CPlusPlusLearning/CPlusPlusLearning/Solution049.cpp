#include "Solution049.h"

std::vector<int> Solution049::getRow(int rowIndex)
{
   std::vector<int> rowPrevious{ 1 };
   for (size_t i{}; i < rowIndex; i++)
   {
      std::vector<int> row{};
      row.reserve(i + 1);
      row.push_back(1);
      for (size_t j{ 1 }; j < rowPrevious.size(); j++)
         row.push_back(rowPrevious[j] + rowPrevious[j - 1]);
      row.push_back(1);
      rowPrevious = move(row);
   }
   return rowPrevious;
}
