/**************************************************************************
 * File Name : 523-ContinuousSubarraySum.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-02-2017
 *
 * Last Modified : Tue Feb 28 10:23:07 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0){
            for(int i=0; i<n-1; i++){
                if(nums[i] == 0 && nums[i+1] == 0) return true;
            }
            return false;
        }
        
        vector<int> dp(n);
        for(int i=0; i<n; i++) dp[i] = nums[i];
        
        for(int len = 2; len<=n; len++){
            for(int i=0; len+i-1 < n; i++) {
                dp[i] += nums[len+i-1];
                if (dp[i]%k == 0) return true;
            }
        }
        
        return false;
    }
};

// Hashmap: keep track of remaing modules since that perserves add
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp{{0,-1}}; //{module, index};

        int cumsum = 0;
        for(int i=0; i<n; i++){
            cumsum += nums[i];
            if(k!=0) cumsum %= k;
            if(mp.find(cumsum) != mp.end()) {
                if(i - mp[cumsum] > 1) return true;
            }
            else mp[cumsum] = i;
        }
        
        return false;
    }
};
