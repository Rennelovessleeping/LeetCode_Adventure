/**************************************************************************
 * File Name : 34-SearchForARange.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-01-2017
 *
 * Last Modified : Sat Jan 21 21:39:24 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Binary search + local search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target) return localSearch(nums, mid);
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        return vector<int>{-1,-1}; 
        
    }
    
private:
    vector<int> localSearch(vector<int>& nums, int idx){
        int target = nums[idx];
        int left = idx, right = idx;
        while(left > 0 && nums[left]==nums[left-1]) left--;
        while(right < nums.size()-1 && nums[right]==nums[right+1]) right++;
        
        return vector<int> {left, right};
    }

};

// Use Binary Search to find the left and right boundary
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2,-1);
        
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid - 1; // combine the case of nums[mid] == target and nums[mid] > target, since in these two cases, right moves
			// left in order to search for the left boundary
        }
        if ( left >= nums.size() || nums[left]!=target) return ans;
        ans[0] = left;
        
        right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        ans[1] = right;
        return ans;
        
    }

};
