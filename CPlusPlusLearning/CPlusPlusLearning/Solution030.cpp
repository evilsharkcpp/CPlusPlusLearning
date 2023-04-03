#include "Solution030.h"

void Solution030::rotate(std::vector<std::vector<int>>& matrix)
{
   size_t n{ matrix.size() };
   for (size_t i{}; i < n / 2; i++)
      for (size_t j{ i }; j < n - i - 1; j++)
      {
         std::swap(matrix[i][j], matrix[j][n - 1 - i]);
         std::swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
         std::swap(matrix[i][j], matrix[n - 1 - j][i]);
      }
}
