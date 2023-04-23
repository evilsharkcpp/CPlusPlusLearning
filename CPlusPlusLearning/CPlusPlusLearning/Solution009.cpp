#include "Solution009.hpp"

ListNode* Solution009::mergeKLists(std::vector<ListNode*>& lists)
{
   ListNode* head = {};
   for (auto& list : lists)
   {
      head = mergeTwoLists(list, head);
   }
   return head;
}

ListNode* Solution009::mergeTwoLists(ListNode* list1, ListNode* list2)
{
   ListNode* root = new ListNode();
   ListNode* res = root;
   while (list1 != nullptr && list2 != nullptr)
   {
      if (list1->val < list2->val)
      {
         root->next = list1;
         list1 = list1->next;
      }
      else
      {
         root->next = list2;
         list2 = list2->next;
      }
      root = root->next;
   }
   if (list1 != nullptr)
      root->next = list1;
   if (list2 != nullptr)
      root->next = list2;
   return res->next;
}
