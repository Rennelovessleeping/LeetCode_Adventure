/**************************************************************************
 * File Name : 543-DiameterOfBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 11:36:36 2017
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, int& res) { // return max depth
       if(!root) return 0;
       int l = helper(root->left, res);
       int r = helper(root->right, res);

       res = max(res, l+r); 
       
       return max(l,r)+1;
    }
};
