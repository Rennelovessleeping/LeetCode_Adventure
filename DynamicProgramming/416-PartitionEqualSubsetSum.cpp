/**************************************************************************
 * File Name : 416-PartitionEqualSubsetSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-03-2017
 *
 * Last Modified : Fri Mar 31 22:34:41 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// 01 knapsack problem
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        
        sum /= 2;
        vector<vector<bool>> dp(len+1, vector<bool>(sum+1, false)); 
        // dp[i][j] -- whether target = j can be obtained from first i numbers;
        
        // Initialization
        dp[0][0] = true; // target=0 can be obtained from 0 numbers;
        for(int i=1; i<=len; i++) dp[i][0] = true; // empty subset
        for(int j=1; j<=sum; j++) dp[0][j] = false; 
        
        // update dp table
        for(int i=1; i<=len; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[len][sum];
    }
};

// optimization 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0) return false;
        
        sum /= 2;
        vector<bool> dp(sum+1, false); 
        
        // Initialization
        dp[0] = true; // target=0 can be obtained from 0 numbers;
        
        // update dp table
        for(const auto& num:nums){
            for(int j=sum; j>=num; j--){
                dp[j] = dp[j] || dp[j-num];
            }
        }
        
        return dp[sum];
    }
};
