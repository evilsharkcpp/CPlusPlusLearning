#include "Solution057.hpp"
#include <stack>

bool Solution057::isSameTreeWithoutRecursion(TreeNode* p, TreeNode* q)
{
   std::stack<TreeNode*> pRoots{}, qRoots;
   while ((!pRoots.empty() || p != nullptr) && ((!qRoots.empty() || q != nullptr)))
   {
      if (p != nullptr || q != nullptr)
      {
         if (p != nullptr)
         {
            pRoots.push(p);
            p = p->left;
         }
         if (q != nullptr)
         {
            qRoots.push(q);
            q = q->left;
         }
      }
      else
      {
         p = pRoots.top();
         q = qRoots.top();
         pRoots.pop();
         qRoots.pop();

         if (q->val != p->val || pRoots.size() != qRoots.size())
            return false;
         q = q->right;
         p = p->right;
      }
   }
   return p == nullptr && q == nullptr;
}

bool Solution057::isSameTreeRecursion(TreeNode* p, TreeNode* q)
{
   if (p == nullptr && q == nullptr)
      return true;
   return (p != nullptr && q != nullptr && p->val == q->val) &&
      isSameTreeRecursion(p->left, q->left) && isSameTreeRecursion(p->right, q->right);
}
