#pragma once
#include <string>
#include <vector>
#include "ListNode.h"


class Solution
{
public:
   ///<summary>
   /// https://leetcode.com/problems/regular-expression-matching/
   ///</summary>
   bool isMatch(std::string text, std::string pattern);

   ///<summary>
   /// https://leetcode.com/problems/container-with-most-water/
   ///</summary>
   int maxArea(std::vector<int>& height);

   ///<summary>
   /// https://leetcode.com/problems/longest-common-prefix/
   ///</summary>
   std::string longestCommonPrefix(std::vector<std::string>& strs);

   ///<summary>
   /// https://leetcode.com/problems/merge-two-sorted-lists/
   /// This is func used raw pointers
   ///</summary>
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

};