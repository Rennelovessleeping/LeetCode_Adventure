/**************************************************************************
 * File Name : 300-LongestIncreasingSubsequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-02-2017
 *
 * Last Modified : Wed Feb 15 18:56:13 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(n^2) DP solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(),1); // the length of LIS ending at i should be at least 1: e.g. only nums[i] counts
        int maxLen = 1;
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};


// O(NlogN) solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            auto resIter = lower_bound(res.begin(), res.end(), nums[i]);
            if(resIter == res.end()) res.push_back(nums[i]);
            else *resIter = nums[i]; // replace the value larger than nums[i] with it;
        }
        
        return res.size();
    }
};
