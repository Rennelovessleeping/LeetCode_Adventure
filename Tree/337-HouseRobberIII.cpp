/**************************************************************************
 * File Name : 337-HouseRobberIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-02-2017
 *
 * Last Modified : Sun Feb  5 23:09:59 2017
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
    int rob(TreeNode* root) {
        if(!root) return 0;
        return max(rob(root->left)+rob(root->right), 
                root->val + (root->left ? rob(root->left->left)+rob(root->left->right) : 0) 
                + (root->right ? rob(root->right->left)+rob(root->right->right) : 0) );
    }
};

// Store some results during the recursion to boost up speed: record the max sum with and without current node
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }

private:
    vector<int> helper(TreeNode *root){
        // res[0]: max sum with current node inclusive; res[1] max sum with current node excluded;
        if(!root) return {0,0};
        
        vector<int> l = helper(root->left), r =  helper(root->right), res={0,0};
        res[0] = root->val + l[1] + r[1];
        res[1] = max(l[0], l[1]) + max(r[0], r[1]);
        
        return res;
    }
};
