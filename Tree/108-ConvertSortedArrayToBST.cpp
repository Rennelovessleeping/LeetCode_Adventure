/**************************************************************************
 * File Name : 108-ConvertSortedArrayToBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-01-2017
 *
 * Last Modified : Tue Jan 31 22:47:52 2017
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
private:
    TreeNode* helper(int start, int end, vector<int>& nums){
        if(start > end) return nullptr;
        int mid = start + (end - start + 1)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(start, mid-1, nums);
        root->right = helper(mid+1, end, nums);
        return root;
    } 
    
};

