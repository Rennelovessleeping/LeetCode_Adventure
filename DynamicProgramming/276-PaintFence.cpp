/**************************************************************************
 * File Name : 276-PaintFence.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-02-2017
 *
 * Last Modified : Sun Feb 26 12:37:25 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int numWays(int n, int k) {
        if(n==0) return 0;
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[0][0] = 0; 
        dp[0][1] = k;
        for(int i=1; i<n; i++){
            dp[i][0] = dp[i-1][1]; // keep painting i'th house the same color as i-1'th
            dp[i][1] = (dp[i-1][0] + dp[i-1][1])* (k-1); // different color;
        }
        return dp[n-1][0] + dp[n-1][1];
    }
};
