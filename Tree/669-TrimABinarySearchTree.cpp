/**************************************************************************
 * File Name : 669-TrimABinarySearchTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-09-2017
 *
 * Last Modified : Fri Sep 22 14:59:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return nullptr;
        else if(root->val < L) return trimBST(root->right, L, R);
        else if(root->val > R) return trimBST(root->left, L, R);
        
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        
        return root;
    }
};
