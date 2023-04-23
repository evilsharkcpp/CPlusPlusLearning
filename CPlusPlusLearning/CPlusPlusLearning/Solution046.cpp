#include "Solution046.hpp"
#include <functional>
#include <stack>

std::vector<int> Solution046::inorderTraversalRecursive(TreeNode* root)
{
   std::vector<int> result{};
   std::function<void(TreeNode*)> inOrder
   {
       [&](TreeNode* node)
       {
           if (node == nullptr)
               return;
           inOrder(node->left);
           result.push_back(node->val);
           inOrder(node->right);
       }
   };
   inOrder(root);
   return result;
}

std::vector<int> Solution046::inorderTraversal(TreeNode* root)
{
   std::vector<int> result{};
   std::stack<TreeNode*> roots{};
   while (!roots.empty() || root != nullptr)
   {
      if (root != nullptr)
      {
         roots.push(root);
         root = root->left;
      }
      else
      {
         root = roots.top();
         roots.pop();
         result.push_back(root->val);
         root = root->right;
      }
   }
   return result;
}
