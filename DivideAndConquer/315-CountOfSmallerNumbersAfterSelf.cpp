/**************************************************************************
 * File Name : 315-CountOfSmallerNumbersAfterSelf.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-03-2017
 *
 * Last Modified : Tue Mar 21 21:28:01 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Construct BST from back
class Solution {
public:
    struct TreeNode{
        int val, sum, dup;
        TreeNode *left, *right;
        TreeNode(int val, int sum): dup(1), left(nullptr), right(nullptr) {
            this->val = val;
            this->sum = sum;
        }
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        TreeNode *root = nullptr;
        for(int i=nums.size()-1; i>=0; i--){
            root = insert(nums[i], i, root, 0, res);
        }
        
        return res;
    }
private:
    TreeNode* insert(int num, int i, TreeNode* root, int preSum, vector<int>& res){
        if(!root) {
            root = new TreeNode(num, 0);
            res[i] = preSum;
        }
        else if(num == root->val){
            root->dup++;
            res[i] = preSum + root->sum;
        }
        else if(num < root->val){
            root->sum++;
            root->left = insert(num, i, root->left, preSum, res);
        }
        else{
            root->right = insert(num, i, root->right, preSum + root->sum + root->dup, res);
        }
        return root;
    }
};
