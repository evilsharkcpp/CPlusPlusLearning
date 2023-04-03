#include "Solution021.h"

ListNode* Solution021::swapPairs(ListNode* firstHead)
{
   if (firstHead == nullptr || firstHead->next == nullptr)
      return firstHead;
   auto secondHead{ firstHead->next },
      next{ secondHead->next };
   secondHead->next = firstHead;
   firstHead->next = next;
   firstHead = secondHead;
   firstHead->next->next = swapPairs(next);
   return firstHead;
}
