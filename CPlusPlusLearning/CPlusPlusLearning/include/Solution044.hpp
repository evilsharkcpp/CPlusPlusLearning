#pragma once
#include "ListNode.h"

class Solution044
{
public:
   ///<summary>
   /// https://leetcode.com/problems/remove-duplicates-from-sorted-list
   /// LeetCode used raw pointers
   ///</summary>
   ListNode* deleteDuplicatesRecursive(ListNode* head);

   ListNode* deleteDuplicatesIntoInput(ListNode* head);

   //This method create new list and add nodes without duplicates
   ListNode* deleteDuplicates(ListNode* head);
};

