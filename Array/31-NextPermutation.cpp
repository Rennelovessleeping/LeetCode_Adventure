/**************************************************************************
 * File Name : 31-NextPermutation.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-02-2017
 *
 * Last Modified : Tue Feb 28 12:15:36 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = len-1;
        for(; i>0 && nums[i-1] >= nums[i]; i--) {}
        
        if(i>0) {
            int j = len-1;
            for(; j>i && nums[j] <= nums[i-1]; j--) {} // not the mean, but the first elem larger than nums[i-1]
            swap(nums[i-1], nums[j]);
        }
        reverse(nums.begin()+i, nums.end());
        
    }
};
