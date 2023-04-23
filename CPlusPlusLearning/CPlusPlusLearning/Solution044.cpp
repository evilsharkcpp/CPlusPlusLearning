#include "Solution044.hpp"

ListNode* Solution044::deleteDuplicatesRecursive(ListNode* head)
{
   if (head == nullptr)
      return nullptr;
   if (head->next == nullptr)
      return head;
   ListNode* node{ nullptr };
   if (head->val == head->next->val)
   {
      node = head->next;
      head->next = node->next;
      delete node;
      deleteDuplicatesRecursive(head);
   }
   else
      deleteDuplicatesRecursive(head->next);
   return head;
}

ListNode* Solution044::deleteDuplicatesIntoInput(ListNode* head)
{
   auto current{ head };
   while (current != nullptr && current->next != nullptr)
   {
      if (current->val == current->next->val)
      {
         auto node{ current->next };
         current->next = node->next;
         delete node;
      }
      else
         current = current->next;
   }
   return head;
}

ListNode* Solution044::deleteDuplicates(ListNode* head)
{
   if (head == nullptr)
      return head;
   auto root{ new ListNode(head->val) };
   auto current{ head }, rootCurrent{ root };
   while (current != nullptr)
   {
      if (current->val != rootCurrent->val)
      {
         rootCurrent->next = new ListNode(current->val);
         rootCurrent = rootCurrent->next;
      }
      current = current->next;
   }
   return root;
}
