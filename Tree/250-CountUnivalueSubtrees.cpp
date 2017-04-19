/**************************************************************************
 * File Name : 250-CountUnivalueSubtrees.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-04-2017
 *
 * Last Modified : Tue Apr 18 19:55:02 2017
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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        isUnivalueSubtree(root, res);
        return res;
    }
    
    bool isUnivalueSubtree(TreeNode* root, int& res) { 
        if(!root) return true;
        bool l = isUnivalueSubtree(root->left, res);
        bool r = isUnivalueSubtree(root->right, res);
        if(l && r && (!root->left || root->val == root->left->val) && (!root->right || root->val == root->right->val)) 
        {
            res++;
            return true;
        }
        return false;
    }
};
