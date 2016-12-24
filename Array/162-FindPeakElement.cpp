/**************************************************************************
 * File Name : 162-FindPeakElement.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-12-2016
 *
 * Last Modified : Fri Dec 23 15:27:44 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Divide and Conquer
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        if (nums.size()==1) return 0;
        
        int mid = nums.size()/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
        if(nums[mid] <= nums[mid-1]){
            vector<int> subNums(nums.begin(), nums.begin()+mid);
            return 0 + findPeakElement(subNums);
        }    
        else{
            vector<int> subNums(nums.begin()+mid, nums.end());
            return mid + findPeakElement(subNums);
        }
        return mid;
        
    }
};
