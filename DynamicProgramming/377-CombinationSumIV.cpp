/**************************************************************************
 * File Name : 377-CombinationSumIV.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-02-2017
 *
 * Last Modified : Tue Feb 14 22:33:05 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1; // only happens when target exactly equals to one of nums
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if((i-nums[j]) >= 0) dp[i] += dp[i-nums[j]];
            }
        }
        return  dp[target];
    }
};
