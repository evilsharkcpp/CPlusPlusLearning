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

   //week 20.02 - 26.02

   ///<summary>
   /// https://leetcode.com/problems/3sum/
   ///</summary>
   std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

   ///<summary>
   /// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
   ///</summary>
   std::vector<std::string> letterCombinations(std::string digits);

   ///<summary>
   /// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
   ///</summary>
   ListNode* removeNthFromEnd(ListNode* head, int n);

   ///<summary>
   /// https://leetcode.com/problems/valid-parentheses/
   ///</summary>
   bool isValid(std::string s);

   ///<summary>
   /// https://leetcode.com/problems/merge-k-sorted-lists/
   ///</summary>
   ListNode* mergeKLists(std::vector<ListNode*>& lists);

   ///<summary>
   /// https://leetcode.com/problems/generate-parentheses/
   ///</summary>
   std::vector<std::string> generateParenthesis(int n);

   //week 27.02 - 5.03

   ///<summary>
   /// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
   ///</summary>
   int removeDuplicates(std::vector<int>& nums);

   ///<summary>
   /// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
   ///</summary>
   int strStr(std::string haystack, std::string needle);

   ///<summary>
   /// https://leetcode.com/problems/search-in-rotated-sorted-array/
   ///</summary>
   int search(std::vector<int>& nums, int target);
};