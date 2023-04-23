#include "Solution045.hpp"
#include <unordered_set>

bool Solution045::hasCycle(ListNode* head)
{
   std::unordered_set<ListNode*> seen{};
   while (head != nullptr)
   {
      if (seen.count(head) != 0)
         return true;
      seen.emplace(head);
      head = head->next;
   }
   return false;
}

bool Solution045::hasCycleConstantMemory(ListNode* head)
{
   auto fast{ head }, slow{ head };
   while (fast != nullptr && fast->next != nullptr)
   {
      fast = fast->next;
      if (fast != nullptr)
         fast = fast->next;
      slow = slow->next;
      if (fast == slow)
         return true;
   }
   return false;
}
