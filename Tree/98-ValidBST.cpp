/**************************************************************************
 * File Name : 98-ValidBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-02-2017
 *
 * Last Modified : Tue Feb 21 21:39:13 2017
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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if (!isValidBST(root->left) || !isValidBST(root->right)) return false;
        
        TreeNode *l = root->left, *r = root->right;
        while(l && l->right) l = l->right;
        while(r && r->left) r = r->left;
        
        if(l && l->val >= root->val) return false;
        if(r && r->val <= root->val) return false;
        
        return true;
    }
};

// Inorder traversal solution: the current visted node's value should always be bigger than previous node's;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = nullptr;
        return inorder(root, pre);
    }
    
    bool inorder(TreeNode* root, TreeNode* &pre){ // pre is the traversor
        if(!root) return true;
        if(!inorder(root->left, pre)) return false;
        if(pre && pre->val >= root->val) return false;
        pre = root;
        return inorder(root->right, pre);
    }
};
