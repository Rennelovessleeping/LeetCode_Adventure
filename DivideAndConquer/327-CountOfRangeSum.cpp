/**************************************************************************
 * File Name : 327-CountOfRangeSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-03-2017
 *
 * Last Modified : Tue Mar 21 22:22:47 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Divide and Conquer solution
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() == 0 || lower > upper) return 0;
        return countRangeSum(nums, lower, upper, 0, nums.size()-1);
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper, int l, int r){
        if(l == r) return nums[l] >= lower && nums[r] <= upper;
        
        int mid = l + (r-l)/2;
        vector<long> prefix(r-mid,0);
        long int sum = 0;
        for(int i=mid+1; i<=r; i++){
            sum += nums[i];
            prefix[i-(mid+1)] = sum; 
        }
        
        sort(prefix.begin(), prefix.end());
        sum = 0;
        int count = 0;
        for(int i=mid; i>=l; i--){
            sum += nums[i];
            count += findIdx(prefix, upper-sum+0.5) - findIdx(prefix, lower-sum-0.5); // lenght;
        }
        
        return count + countRangeSum(nums, lower, upper, l, mid) + countRangeSum(nums, lower, upper, mid+1, r);
        
    }
private:
    int findIdx(const vector<long>& arr, double target){ // search for the one-pass-end idx
        int l = 0, r = arr.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};
