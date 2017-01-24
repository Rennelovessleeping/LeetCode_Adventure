/**************************************************************************
 * File Name : 236-LACofBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-01-2017
 *
 * Last Modified : Tue Jan 24 16:15:52 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Write a function to judge whether a node belonging to a tree using DFS;
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(isAncestor(root->left, p) && isAncestor(root->left, q)) 
            return lowestCommonAncestor(root->left, p, q);
        if(isAncestor(root->right, p) && isAncestor(root->right, q))
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
        
    }
    
private:
    bool isAncestor(TreeNode* root, TreeNode* target){
        if (!root) return false;
        if(root == target) return true;
        return isAncestor(root->left, target) || isAncestor(root->right, target);
    }
    
};

// Direct recursive solution
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || root == p || root == q) return root;
        TreeNode* leftAncestor = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAncestor = lowestCommonAncestor(root->right, p, q);
        
        
        // when neither of left and right ancestor is null, return root since p and q are on diff subtrees.
        return !leftAncestor ? rightAncestor : !rightAncestor ? leftAncestor : root;
        
    }
    
};
