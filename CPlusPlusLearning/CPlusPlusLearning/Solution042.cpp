#include "Solution042.hpp"
#include <vector>

int Solution042::climbStairs(int n)
{
   std::vector<int> dp{};
   dp.reserve(n + 1);
   dp.push_back(1);
   dp.push_back(1);
   for (int i{ 2 }; i <= n; i++)
      dp.push_back(dp[i - 1] + dp[i - 2]);
   return dp.back();
}

int Solution042::climbStairsOptimizedMemory(int n)
{
   int numberFirst{ 1 }, numberSecond{ 1 }, result{ 1 };
   for (int i{ 2 }; i <= n; i++)
   {
      result = numberFirst + numberSecond;
      numberFirst = numberSecond;
      numberSecond = result;
   }
   return result;
}
