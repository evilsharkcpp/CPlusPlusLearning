#include "Solution001.h"
#include<vector>

bool Solution001::isMatch(std::string text, std::string pattern)
{
   size_t m = text.length(), n = pattern.length();
   auto dp = std::vector<std::vector<bool>>(m + 1, std::vector<bool>(n + 1, false));
   dp[m][n] = true;

   for (int i = m; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--)
      {
         bool first_match = (i < m &&
            (pattern[j] == text[i] ||
               pattern[j] == '.'));
         if (j + 1 < n && pattern[j + 1] == '*')
            dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
         else
            dp[i][j] = first_match && dp[i + 1][j + 1];
      }
   return dp[0][0];
}
