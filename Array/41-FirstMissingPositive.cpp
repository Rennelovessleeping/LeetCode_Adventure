/**************************************************************************
 * File Name : 41-FirstMissingPositive.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-03-2017
 *
 * Last Modified : Sun Mar 12 13:54:13 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            // put positive integer in the right place;
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
        }
        for(int i=0; i<n; i++){
            if(nums[i] != i+1) return i+1;
        }
        return n + 1;
    }
};
