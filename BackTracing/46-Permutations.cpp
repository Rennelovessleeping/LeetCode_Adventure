/**************************************************************************
 * File Name : 46-Permutations.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-02-2017
 *
 * Last Modified : Tue Feb 28 13:41:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// The idea of permutation is simple, just permute it; But dont permute the permuted one
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
    
private:
    void helper(vector<vector<int>>& res, vector<int>&nums, int pos){
        if(pos == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i=pos; i<nums.size(); i++){
            swap(nums[i], nums[pos]);
            helper(res, nums, pos+1);
            swap(nums[i], nums[pos]);
        }
        
    }
};

// Solution using void nextPermutation(vector<int>& nums);
// nums has to be sorted first it not !!!
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int totNum = factorial(n);
        
        vector<vector<int>> res;
        for(int i=0; i<totNum; i++){
            nextPermutation(nums);
            res.push_back(nums);
        }
        
        return res;
    }
private:
    int factorial(int n){
        if(n == 1 || n == 0) return 1;
        return n*factorial(n-1);
    }
    void nextPermutation(vector<int>& nums){
        int len = nums.size();
        int i = len-1;
        for(; i>0 && nums[i-1] >= nums[i]; i--){};
        if(i>0){
            int j = len-1;
            for(; j>i && nums[j] <= nums[i-1]; j--) {}
            swap(nums[i-1], nums[j]);
        }
        reverse(nums.begin()+i, nums.end());
    }
};


