/**************************************************************************
 * File Name : 111-MinimumDepthOfBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-01-2017
 *
 * Last Modified : Tue Jan 24 13:37:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Raw DFS solution
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return helper(root);
    }
    
private:
    int helper(TreeNode* root) {
        
        if(!root->left && !root->right) return 1;
        if(!root->left) return 1 + helper(root->right);
        else if(!root->right) return 1+ helper(root->left);
        else return 1+min(helper(root->left), helper(root->right));
    }
};

// Consice solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
    
};
