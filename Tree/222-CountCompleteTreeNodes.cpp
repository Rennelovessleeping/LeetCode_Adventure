/**************************************************************************
 * File Name : 222-CountCompleteTreeNodes.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-01-2017
 *
 * Last Modified : Tue Jan 24 16:47:51 2017
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
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        int lh=0, rh=0;

        TreeNode *l=root->left, *r=root->right;
        
        while(l) {lh++; l = l->left;}
        while(r) {rh++; r = r->left;}
       
        if(lh==rh) return (1<<lh) + countNodes(root->right); // 1(root) + 2^lh-1(left full binary subtree) + full nodes of right subtree
        else return (1<<rh) + countNodes(root->left);
        
    }
    
private:
    int bruteForceCount(TreeNode* root){
        if(!root) return 0;
        return 1 + bruteForceCount(root->left) + bruteForceCount(root->right);
    }
    
};
