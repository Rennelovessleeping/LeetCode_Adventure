/**************************************************************************
 * File Name : 654-MaximumBinaryTree.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-09-2017
 *
 * Last Modified : Fri Sep 22 16:30:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(nlogn) top-down recursive solution is trivial
// O(n) solution using stack: since each element get added into and poped from a stack just once -> no need to go through all levels
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        vector<TreeNode*> stk;
        for(int i=0; i<nums.size(); i++) {
            TreeNode *p = new TreeNode(nums[i]);
            while(!stk.empty() && stk.back()->val < nums[i]) {
                p->left = stk.back();
                stk.pop_back();
            }
            if(!stk.empty()) stk.back()->right = p;
            stk.push_back(p);
        }
        return stk.front();
    }
};
