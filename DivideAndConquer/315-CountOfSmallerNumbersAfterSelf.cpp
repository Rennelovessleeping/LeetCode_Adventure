/**************************************************************************
 * File Name : 315-CountOfSmallerNumbersAfterSelf.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-03-2017
 *
 * Last Modified : Thu Mar 23 00:10:41 2017
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

// Merge-Sort based solution
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> sortingIdx(n, 0);
        iota(sortingIdx.begin(), sortingIdx.end(), 0);
        merge_count_small(nums, sortingIdx, 0, n, res);
        return res;
    }
    
private:
    void merge_count_small(vector<int>& nums, vector<int>& sortingIdx, int left, int right, vector<int>& res){
        if(right - left <= 1) return;
        
        int mid = left + (right-left)/2;
        merge_count_small(nums, sortingIdx, left, mid, res);
        merge_count_small(nums, sortingIdx, mid, right, res);
        vector<int> tmp; // tmp stores the sorted index;
        
        int i = left, j = mid;
        int semicount = 0;
        while(i<mid || j<right){
            if(j == right || (i<mid && nums[sortingIdx[i]] <= nums[sortingIdx[j]]) ){ 
			// when the ends of first half and second half are equally small, merge from first half first;
                tmp.push_back(sortingIdx[i]);
                res[sortingIdx[i]] += semicount;
                i++;
            }
            else{ // merge elem from second half;
                tmp.push_back(sortingIdx[j]);
                semicount++; // for all later elem from first half;
                j++;
            }
        }
        
        move(tmp.begin(), tmp.end(), sortingIdx.begin() + left);
        
    }
};
