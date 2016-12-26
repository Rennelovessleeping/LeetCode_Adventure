/**************************************************************************
 * File Name : 100-SameTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-12-2016
 *
 * Last Modified : Mon Dec 26 12:09:49 2016
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p || !q) return !p && !q;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
    
};
