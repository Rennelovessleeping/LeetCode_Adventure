/**************************************************************************
 * File Name : 112-PathSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-01-2017
 *
 * Last Modified : Mon Jan 23 23:02:20 2017
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        genPath(0, root, sum);
        return counter > 0;
    }
    
private:
    int counter = 0;
    void genPath(int curSum, TreeNode* root, int sum){
        //if (counter>0) return;
        if(!root->left && !root->right) {
            if (curSum+root->val == sum) counter++;
            return;
        }
        
        curSum += root->val; // Don't stop when curSum > sum, since this is not a positive binary tree!!!
        if(root->left) genPath(curSum, root->left, sum);
        if(root->right) genPath(curSum, root->right, sum);
        
    }
};

// Consice solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right && root->val==sum) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    
};
