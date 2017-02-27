/**************************************************************************
 * File Name : 124-BinaryTreeMaximumPathSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-02-2017
 *
 * Last Modified : Sun Feb 26 21:45:09 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Bottom up recursion
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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* root, int& maxSum){ // return max path sum bottome up to current node
        if(!root) return 0;
        int l = dfs(root->left, maxSum);
        int r = dfs(root->right, maxSum);
        if(l<0) l = 0; // if the max sum up to left child is negative , discard it;
        if(r<0) r = 0;
        maxSum = max(maxSum, root->val + l + r);
        return root->val += max(r,l);
    }
};
