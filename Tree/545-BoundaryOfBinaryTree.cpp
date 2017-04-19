/**************************************************************************
 * File Name : 545-BoundaryOfBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-04-2017
 *
 * Last Modified : Tue Apr 18 22:43:35 2017
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
    vector<int> res;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return res;
        res.push_back(root->val);
        leftBoundary(root->left);
        leaf(root->left);
        leaf(root->right);
        rightBoundary(root->right);
        return res;
        
    }
    
    void leftBoundary(TreeNode* root){
        if(!root || (!root->left && !root->right)) return;
        
        res.push_back(root->val);
        if(root->left) leftBoundary(root->left);
        else leftBoundary(root->right);
    }
    
    void rightBoundary(TreeNode* root){ // post-order
        if(!root || (!root->left && !root->right)) return;
        
        if(root->right) rightBoundary(root->right);
        else rightBoundary(root->left);
        res.push_back(root->val);
    }
    
    void leaf(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        
        leaf(root->left);
        leaf(root->right);
    }
};
