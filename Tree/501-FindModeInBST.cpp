/**************************************************************************
 * File Name : 501-FindModeInBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-04-2017
 *
 * Last Modified : Mon Apr 17 21:22:52 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(1) solution + two pass
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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        modes.resize(modeCount);
        
        curCount = 0;
        modeCount = 0;
        inorder(root);
        
        return modes;
    }
private:
    int modeCount = 0, maxCount = 0;
    int curVal = 0, curCount = 0;
    vector<int> modes;
    
    void count_mode(int val) {
        if(curVal != val) {
            curVal = val;
            curCount = 0;
        }
        
        curCount++;
        if(curCount > maxCount) {
            maxCount = curCount;
            modeCount = 1;
        }
        else if(curCount == maxCount) {
            if(modes.size() != 0) modes[modeCount] = curVal;
            modeCount++;
        }
    }
    
    void inorder(TreeNode* root) { // from small to large
        if(!root) return;
        inorder(root->left);
        count_mode(root->val);
        inorder(root->right);
    }
};
