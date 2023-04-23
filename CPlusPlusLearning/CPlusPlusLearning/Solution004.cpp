#include "Solution004.hpp"

ListNode* Solution004::mergeTwoLists(ListNode* list1, ListNode* list2)
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
