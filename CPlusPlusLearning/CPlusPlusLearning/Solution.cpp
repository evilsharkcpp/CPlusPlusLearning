#include "Solution.h"
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>

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

std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums)
{
   std::vector<std::vector<int>> result{};
   std::set<std::vector<int>> s{};
   std::sort(nums.begin(), nums.end());
   for (int i{ 0 }; i < nums.size() - 2 && nums[i] <= 0; i++)
   {
      int left = i + 1;
      int right = nums.size() - 1;
      while (right > left)
      {
         int sum = nums[i] + nums[left] + nums[right];
         if (sum == 0)
         {
            s.insert({ nums[i], nums[left], nums[right] });
            //ignore duplicates of nums[left]
            while (left < right && nums[left] == nums[left + 1]) left++;
            //ignore duplicates of nums[right]
            while (left < right && nums[right] == nums[right - 1]) right--;
            left++;
            right--;
         }
         else
            if (sum > 0)
               right--;
            else
               left++;
         while (i < nums.size() - 2 && nums[i] == nums[i + 1]) i++;
      }
   }
   result.assign(s.begin(), s.end());
   return result;
}

std::vector<std::string> Solution::letterCombinations(std::string digits)
{
   std::queue<std::string> letters{};
   std::map<char, std::string> container{ {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
   for (auto& ch : digits)
   {
      if (letters.empty())
      {
         for (auto& t : container[ch])
         {
            letters.push(std::string(1, t));
         }
      }
      else
      {
         int queueSize = letters.size();
         for (int i{ 0 }; i < queueSize; i++)
         {
            std::string comb = letters.front();
            letters.pop();
            for (auto& t : container[ch])
            {
               letters.push(comb + std::string(1, t));
            }
         }
      }
   }
   std::vector<std::string> result;
   while (!letters.empty())
   {
      result.push_back(letters.front());
      letters.pop();
   }
   return result;
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
   auto startPtr = head;
   auto middlePtr = head;
   auto middleIndex = 0;
   auto size = 0;
   while (startPtr != nullptr)
   {
      startPtr = startPtr->next;
      if (middleIndex++ % 2 == 0)
         middlePtr = middlePtr->next;
      size++;
   }
   auto removeIndex = size - n;
   if (removeIndex == 0)
      return head->next;
   if (removeIndex > middleIndex)
   {
      while (middleIndex++ != removeIndex - 1)
         middlePtr = middlePtr->next;
      auto tmp = middlePtr->next;
      middlePtr->next = tmp->next;
   }
   else
   {
      auto startIndex = 0;
      startPtr = head;
      while (startIndex++ != removeIndex - 1)
         startPtr = startPtr->next;
      auto tmp = startPtr->next;
      startPtr->next = tmp->next;

   }
   return head;
}

bool Solution::isValid(std::string s)
{
   std::map<char, char> brackets{ {')', '('}, {'}', '{'}, {']', '['} };
   std::stack<char> st{};
   for (auto& ch : s)
   {
      switch (ch)
      {
      case '(':
      case '{':
      case '[':
         st.push(ch);
         break;
      case ')':
      case '}':
      case ']':
         if (!st.empty() && st.top() == brackets[ch])
            st.pop();
         else
            return false;
         break;
      default:
         return false;
         break;
      }
   }
   return st.empty();
}

ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists)
{
   ListNode* head = {};
   for (auto& list : lists)
   {
      head = mergeTwoLists(list, head);
   }
   return head;
}

std::vector<std::string> Solution::generateParenthesis(int n)
{
   std::vector<std::string> res;
   if (n == 0)
      res.push_back("");
   else
      for (int i = 0; i < n; i++)
         for (auto& left : generateParenthesis(i))
            for (auto& right : generateParenthesis(n - 1 - i))
               res.push_back("(" + left + ")" + right);
   return res;
}

int Solution::removeDuplicates(std::vector<int>& nums)
{
   int insertIndex{ 1 };
   for (int i{ 1 }; i < nums.size(); i++)
      if (nums[i - 1] != nums[i])
         nums[insertIndex++] = nums[i];
   return insertIndex;
}

int Solution::strStr(std::string haystack, std::string needle)
{
   for (int i = 0; i < haystack.length(); i++)
   {
      bool isEqual = true;
      for (int k = 0; k < needle.length(); k++)
      {
         if (i + k >= haystack.length())
            return -1;
         if (haystack[i + k] != needle[k])
         {
            isEqual = false;
            break;
         }
      }
      if (isEqual)
         return i;
   }
   return -1;
}

int Solution::search(std::vector<int>& nums, int target)
{
   int start = 0;
   int end = nums.size() - 1;
   int middle = 0;
   while (start <= end)
   {
      middle = start + (end - start) / 2;
      if (nums[middle] == target)
         return middle;
      if (nums[start] <= nums[middle])
      {
         if (target >= nums[start] && target < nums[middle])
            end = middle - 1;
         else
            start = middle + 1;
      }
      else
      {
         if (target <= nums[end] && target > nums[middle])
            start = middle + 1;
         else
            end = middle - 1;
      }
   }
   return -1;
}
