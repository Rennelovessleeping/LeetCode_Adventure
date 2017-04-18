/**************************************************************************
 * File Name : 333-LargestBSTSubtree.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-04-2017
 *
 * Last Modified : Mon Apr 17 22:33:42 2017
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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        int lower, upper;
        isBST(root, res, lower, upper);
        return res;
    }
    
    bool isBST(TreeNode* root, int& res, int& lower, int& upper) {
        if(!root) return true;
        
        int left_size = 0, right_size = 0;
        int left_lower, left_upper, right_lower, right_upper;
        bool left_BST = isBST(root->left, left_size, left_lower, left_upper);
        bool right_BST = isBST(root->right, right_size, right_lower, right_upper);
        
        if(left_BST && right_BST) {
            if((!root->left || left_upper < root->val) && (!root->right || right_lower > root->val)) {
                res = left_size + right_size + 1;
                lower = root->left ? left_lower : root->val;
                upper = root->right ? right_upper : root->val;
                return true;
            }
        }
        
        res = max(left_size, right_size);
        return false;
    }
};
