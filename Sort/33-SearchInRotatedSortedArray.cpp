/**************************************************************************
 * File Name : 33-SearchInRotatedSortedArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-01-2017
 *
 * Last Modified : Thu Jan 26 14:40:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// using min_element()
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), left = 0, right = len-1;
        int pos = min_element(nums.begin(), nums.end()) - nums.begin();
        
        while(left <= right){
            int mid = left + (right-left)/2;
            int midpos = (pos+mid)%len;
            if(nums[midpos] == target) return midpos;
            else if(nums[midpos] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return -1;
    }
    
};


// Using binary search to search for the minimum since the array is sorted
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), left = 0, right = len-1;
        // Binary search to implement min_element();
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]) left = mid+1; // minimum must has been rotated into the right half;
            else right = mid;
            
        }
        
        int pos = left;
        left = 0, right = len-1;
        
        while(left <= right){
            int mid = (right+left)/2;
            int midpos = (pos+mid)%len;
            if(nums[midpos] == target) return midpos;
            else if(nums[midpos] < target) left = mid + 1;
            else right = mid - 1;
        }
        
        return -1;
    }
    
};
