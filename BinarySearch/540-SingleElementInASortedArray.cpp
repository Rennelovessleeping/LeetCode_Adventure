/**************************************************************************
 * File Name : 540-SingleElementInASortedArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-09-2017
 *
 * Last Modified : Sat Sep 16 14:24:59 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Binary Search finding the first pair that nums[2*idx] != nums[2*idx+1]
        int n = nums.size(), left = 0, right = n/2;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(nums[2*mid] != nums[2*mid+1]) right = mid;
            else left = mid+1;
        }
        return nums[left*2];
    }
};
