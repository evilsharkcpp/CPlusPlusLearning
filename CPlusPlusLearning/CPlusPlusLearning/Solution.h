#pragma once
#include <string>
#include <vector>
#include <cmath>
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
   /// On LeetCode List works with raw pointers (including tests)
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
   /// On LeetCode List works with raw pointers (including tests)
   ///</summary>
   ListNode* removeNthFromEnd(ListNode* head, int n);

   ///<summary>
   /// https://leetcode.com/problems/valid-parentheses/
   ///</summary>
   bool isValid(std::string s);

   ///<summary>
   /// https://leetcode.com/problems/merge-k-sorted-lists/
   /// On LeetCode List works with raw pointers (including tests)
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


   // day 27.03

   ///<summary>
   /// https://leetcode.com/problems/search-insert-position
   ///</summary>
   int searchInsert(std::vector<int>& nums, int target);

   ///<summary>
   /// https://leetcode.com/problems/palindrome-number
   ///</summary>
   bool isPalindrome(int x);

   ///<summary>
   /// https://leetcode.com/problems/projection-area-of-3d-shapes
   ///</summary>
   int projectionArea(std::vector<std::vector<int>>& grid);
   int projectionAreaOptimized(std::vector<std::vector<int>>& grid);

   ///<summary>
   /// https://leetcode.com/problems/rectangle-overlap
   ///</summary>
   bool isRectangleOverlap(std::vector<int>& firstRect, std::vector<int>& secondRect);

   ///<summary>
   /// https://leetcode.com/problems/rectangle-area
   ///</summary>
   int computeArea(int xBottomFirst, int yBottomFirst, int xTopFirst, int yTopFirst,
      int xBottomSecond, int yBottomSecond, int xTopSecond, int yTopSecond);

   ///<summary>
   /// https://leetcode.com/problems/circle-and-rectangle-overlapping
   ///</summary>
   bool checkOverlap(int radius, int xCenter, int yCenter,
      int xBottom, int yBottom, int xTop, int yTop);

   ///<summary>
   /// https://leetcode.com/problems/valid-square
   ///</summary>
   bool validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3, std::vector<int>& p4);


   //28.03

   ///<summary>
   /// https://leetcode.com/problems/swap-nodes-in-pairs
   /// On LeetCode List works with raw pointers (including tests)
   ///</summary>
   ListNode* swapPairs(ListNode* firstHead);

   ///<summary>
   /// https://leetcode.com/problems/minimum-time-visiting-all-points
   ///</summary>
   int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points);

   ///<summary>
   /// https://leetcode.com/problems/max-points-on-a-line
   /// That was too hard:)
   ///</summary>
   int maxPoints(std::vector<std::vector<int>>& points);

   ///<summary>
   /// https://leetcode.com/problems/check-if-it-is-a-straight-line
   ///</summary>
   bool checkStraightLine(std::vector<std::vector<int>>& coordinates);

   ///<summary>
   /// https://leetcode.com/problems/check-if-it-is-a-straight-line
   /// This solution use fact, that equation of line can write without divisors.
   ///</summary>
   bool checkStraightLineAnother(std::vector<std::vector<int>>& coordinates);

   ///<summary>
   /// https://leetcode.com/problems/remove-element
   ///</summary>
   int removeElement(std::vector<int>& nums, int val);


   //29.03

   ///<summary>
   /// https://leetcode.com/problems/minimum-area-rectangle
   ///</summary>
   int minAreaRect(std::vector<std::vector<int>>& points);

   ///<summary>
   /// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle
   ///</summary>
   std::vector<int> countPoints(std::vector<std::vector<int>>& points,
      std::vector<std::vector<int>>& queries);

   ///<summary>
   /// https://leetcode.com/problems/k-closest-points-to-origin
   ///</summary>
   std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k);

   ///<summary>
   /// https://leetcode.com/problems/length-of-last-word
   ///</summary>
   int lengthOfLastWord(std::string s);

   ///<summary>
   /// https://leetcode.com/problems/rotate-image
   ///</summary>
   void rotate(std::vector<std::vector<int>>& matrix);

   //30.03

   ///<summary>
   /// https://leetcode.com/problems/largest-triangle-area
   ///</summary>
   double largestTriangleArea(std::vector<std::vector<int>>& points);

   ///<summary>
   /// https://leetcode.com/problems/matrix-cells-in-distance-order
   ///</summary>
   std::vector<std::vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter);

   ///<summary>
   /// https://leetcode.com/problems/permutations
   ///</summary>
   std::vector<std::vector<int>> permute(std::vector<int>& nums);

   ///<summary>
   /// https://leetcode.com/problems/valid-boomerang
   ///</summary>
   bool isBoomerang(std::vector<std::vector<int>>& points);

   ///<summary>
   /// https://leetcode.com/problems/valid-boomerang
   ///</summary>
   int maximumDetonation(std::vector<std::vector<int>>& bombs);

   //31.03

   ///<summary>
   /// https://leetcode.com/problems/mirror-reflection
   ///</summary>
   int mirrorReflection(int p, int q);

   ///<summary>
   /// https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart
   ///</summary>
   int minimumLines(std::vector<std::vector<int>>& stockPrices);

   ///<summary>
   /// https://leetcode.com/problems/add-binary
   ///</summary>
   std::string addBinary(std::string a, std::string b);

   ///<summary>
   /// https://leetcode.com/problems/plus-one
   ///</summary>
   std::vector<int> plusOne(std::vector<int>& digits);

   // 01.04

   ///<summary>
   /// https://leetcode.com/problems/surface-area-of-3d-shapes
   ///</summary>
   int surfaceArea(const std::vector<std::vector<int>>& grid);

   ///<summary>
   /// https://leetcode.com/problems/count-lattice-points-inside-a-circle
   ///</summary>
   int countLatticePoints(const std::vector<std::vector<int>>& circles);
   int countLatticePointsOptimized(const std::vector<std::vector<int>>& circles);

   ///<summary>
   /// https://leetcode.com/problems/climbing-stairs
   ///</summary>
   int climbStairs(int n);
   //This method not contains all middle results
   int climbStairsOptimizedMemory(int n);

   ///<summary>
   /// https://leetcode.com/problems/single-number
   ///</summary>
   int singleNumber(std::vector<int>& nums);
   int singleNumberBitwiseOr(std::vector<int>& nums);

   ///<summary>
   /// https://leetcode.com/problems/remove-duplicates-from-sorted-list
   /// LeetCode used raw pointers
   ///</summary>
   ListNode* deleteDuplicatesRecursive(ListNode* head);
   ListNode* deleteDuplicatesIntoInput(ListNode* head);
   //This method create new list and add nodes without duplicates
   ListNode* deleteDuplicates(ListNode* head);

};