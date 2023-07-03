#pragma once

#include"TreeNode.h"

///<summary>
/// https://leetcode.com/problems/symmetric-tree/
///</summary>
class Solution090 {
public:
    bool isSymmetric(TreeNode* root);
private:
    bool preorder(TreeNode* root1, TreeNode* root2);
};