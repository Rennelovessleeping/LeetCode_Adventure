/**************************************************************************
 * File Name : 101-SymmetricTree-Recursive.cpp
 *
 * Purpose : Solv Q101 using recursive formula.
 *
 * Creation Date : 21-12-2016
 *
 * Last Modified : Wed Dec 21 15:38:22 2016
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
    
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return true;
        return cmpMirrorNodes(root->left, root->right);

    }
        
    bool cmpMirrorNodes(TreeNode* L, TreeNode* R){
        
        if(!L && !R) return true;
        if(!L ^ !R) return false;
        if(L->val != R->val) return false;
        return cmpMirrorNodes(L->right, R->left) && cmpMirrorNodes(L->left, R->right);
    }
    
};
