/**************************************************************************
 * File Name : 156-BinaryTreeUpsideDown.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-04-2017
 *
 * Last Modified : Mon Apr 17 21:41:12 2017
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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left) return root;
        TreeNode *curLeft = root->left, *curRight = root->right;
        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        curLeft->left = curRight;
        curLeft->right = root;
        root->left = root->right = nullptr;
        
        return newRoot;
    }
};
