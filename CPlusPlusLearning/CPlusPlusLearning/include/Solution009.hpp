#pragma once
#include <vector>
#include "ListNode.h"

class Solution009
{
public:
   ///<summary>
   /// https://leetcode.com/problems/merge-k-sorted-lists/
   /// On LeetCode List works with raw pointers (including tests)
   ///</summary>
   ListNode* mergeKLists(std::vector<ListNode*>& lists);

   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};

