/**************************************************************************
 * File Name : 298-BinaryTreeLongestConsecutiveSequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-04-2017
 *
 * Last Modified : Mon Apr 17 22:49:11 2017
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
    int longestConsecutive(TreeNode* root) {
        return helper(root, nullptr, 0);
    }
    
    int helper(TreeNode* root, TreeNode* parent, int len) {
        if(!root) return 0;
        len = parent && parent->val+1 == root->val ? len+1 : 1;
        return max(len, max(helper(root->left, root, len), helper(root->right, root, len)));
    }
};
