#pragma once
#include <vector>
#include "TreeNode.h"

class Solution046
{
public:
   ///<summary>
   /// https://leetcode.com/problems/binary-tree-inorder-traversal
   /// LeetCode used raw pointers
   ///</summary>
   std::vector<int> inorderTraversalRecursive(TreeNode* root);

   std::vector<int> inorderTraversal(TreeNode* root);
};

