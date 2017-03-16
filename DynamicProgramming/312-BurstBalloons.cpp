/**************************************************************************
 * File Name : 312-BurstBalloons.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-03-2017
 *
 * Last Modified : Wed Mar 15 20:28:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> n {1};
        for(auto x:nums) {
            if(x>0) n.push_back(x);
        }
        n.push_back(1);
        int len = n.size();
        
        vector<vector<int>> dp(len, vector<int>(len, 0));
        // dp[i][j] is the maxCoins one can get with i and j as the boundary;
    
        for(int k=2; k<len; k++){
            for(int left = 0; left+k < len; left++){
                int right = left + k;
                for(int i=left+1; i< right; i++)
                    dp[left][right] = max(dp[left][right], n[left]*n[i]*n[right] + dp[left][i]+ dp[i][right]);
                    // last poked balloon i does affect the maxCoin of previosly obtained maxCoin dp[left][i] and dp[i][right] 
            }
        }
        
        return dp[0][len-1];
        
    }
};
