/**************************************************************************
 * File Name : 494-TargetSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-01-2017
 *
 * Last Modified : Wed Jan 25 16:35:11 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        int totSum = accumulate(nums.begin(), nums.end(), 0);
        return totSum<S || ((S+totSum)&1) ? 0 : helper(nums, (S+totSum)>>1);

    }
    
private:
    int helper(vector<int>& nums, int target){
        
        int dp[target+1] = {1};
        // following the current dp process, num[0], num[1]... and their sums will be maked with how may times that can make int j;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--) dp[j] += dp[j-nums[i]];
        }
        
        return dp[target];
    }
    
};
