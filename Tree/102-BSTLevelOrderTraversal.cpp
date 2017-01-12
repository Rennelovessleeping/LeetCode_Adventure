/**************************************************************************
 * File Name : 102-BSTLevelOrderTraversal.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-01-2017
 *
 * Last Modified : Wed Jan 11 23:03:41 2017
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return traversal;
    }
    
private:
    vector<vector<int>> traversal;
    void helper(TreeNode* root, int depth){
        if(!root) return;
        if(traversal.size()==depth) traversal.push_back(vector<int> ());
        traversal[depth].push_back(root->val);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }
    
};

