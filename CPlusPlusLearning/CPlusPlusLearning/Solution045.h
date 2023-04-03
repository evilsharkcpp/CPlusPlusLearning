#pragma once
#include "ListNode.h"

class Solution045
{
public:
   ///<summary>
   /// https://leetcode.com/problems/linked-list-cycle
   /// LeetCode used raw pointers
   ///</summary>
   bool hasCycle(ListNode* head);

   bool hasCycleConstantMemory(ListNode* head);
};

