/**************************************************************************
 * File Name : 35-SearchInsertPosition.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-01-2017
 *
 * Last Modified : Sat Jan 21 21:04:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { 
        
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid -1;
            else left = mid + 1;
        }
        
        return left;
        
    }
};
