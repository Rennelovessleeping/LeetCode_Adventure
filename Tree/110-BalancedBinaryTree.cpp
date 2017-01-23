/**************************************************************************
 * File Name : 110-BalancedBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-01-2017
 *
 * Last Modified : Mon Jan 23 16:40:05 2017
 *
 * Created By :  Renne Bai
**************************************************************************//**
// Top-down recursive solution
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
    bool isBalanced(TreeNode* root) { 
        if(!root) return true;
        return abs(treeHeight(root->left) - treeHeight(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
private:
    int treeHeight(TreeNode* root){
        if(!root) return 0;
        return max(treeHeight(root->left), treeHeight(root->right))+1;
    }
};

//Bottom-up DFS O(N) solution

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
    bool isBalanced(TreeNode* root) { 
        return dfsHeight(root)!=-1;
    }
    
private:
    int dfsHeight(TreeNode* root){
        if(!root) return 0;
        
        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) return -1; //Once detecting imbalance, simply report it.
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight-rightHeight)>1) return -1;
        return max(leftHeight, rightHeight)+1;
    }
};
