/**************************************************************************
 * File Name : 410-SplitArrayLargestSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-02-2017
 *
 * Last Modified : Sun Feb 26 11:48:07 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Binary search
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long int left = 0, right = 0;
        for(int i=0; i<nums.size(); i++){
            left = max(left, (long)nums[i]);
            right += nums[i];
        }
        
        while(left <= right){
            long int mid = (left+right)/2; // Bias towards left
            if(isValidPartition(nums, mid, m)) right = mid - 1;
            else left = mid + 1;
        }
        
        return (int)left;
        
    }
private:
    bool isValidPartition(vector<int>& nums, long int target, int m){
        long sum = 0;
        int count = 1;
        for(auto n:nums){
            sum += n;
            if(sum > target){
                sum = n;
                count++;
                if(count > m) return false;
            }
        }
        return true;
    }
};
