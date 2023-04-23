#include "Solution007.hpp"

ListNode* Solution007::removeNthFromEnd(ListNode* head, int n)
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
