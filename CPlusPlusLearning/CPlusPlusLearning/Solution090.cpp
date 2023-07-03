#include "Solution090.hpp"

bool Solution090::isSymmetric(TreeNode *root) {
    if(root == nullptr) {
        return false;
    }

    return preorder(root->left, root->right); 
}

bool Solution090::preorder(TreeNode *root1, TreeNode *root2) {
    if(root1 == nullptr || root2 == nullptr) {
        return root1 == root2;
    }

    if(root1->val != root2->val) {
        return false;
    }

    return preorder(root1->left, root2->right) && 
    preorder(root1->right, root2->left);
}
