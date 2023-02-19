#include "Solution.h"
#include <vector>

bool Solution::isMatch(std::string text, std::string pattern)
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

int Solution::maxArea(std::vector<int>& height)
{
   int maxSquare = 0;
   int left = 0;
   int right = height.size() - 1;
   while (left < right)
   {
      int h = std::min(height[left], height[right]);
      maxSquare = std::max(maxSquare, h * (right - left));
      if (height[left] < height[right])
         left++;
      else
         right--;
   }
   return maxSquare;
}

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
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

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2)
{
   ListNode* root = new ListNode();
   ListNode* res = root;
   while (list1 != nullptr && list2 != nullptr)
   {
      if (list1->val < list2->val)
      {
         root->next = list1;
         list1 = list1->next;
      }
      else
      {
         root->next = list2;
         list2 = list2->next;
      }
      root = root->next;
   }
   if (list1 != nullptr)
      root->next = list1;
   if (list2 != nullptr)
      root->next = list2;
   return res->next;
}
