/**************************************************************************
 * File Name : 154-FindMinimumInRotatedSortedArrayII.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-01-2017
 *
 * Last Modified : Thu Jan 26 14:59:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]) left = mid +1;
            else if(nums[mid] < nums[right]) right = mid;
            else right--; // duplicates;
        }
        
        return nums[left];
    }
};


