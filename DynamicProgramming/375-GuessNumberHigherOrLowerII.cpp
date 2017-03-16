/**************************************************************************
 * File Name : 375-GuessNumberHigherOrLowerII.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-03-2017
 *
 * Last Modified : Wed Mar 15 22:00:18 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int getMoneyAmount(int n) {
        
        if(n==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // dp[i][j] money guarantee to win when choosing number from(i, j);
        // dp[i][i] = 0 --> always win;
        // dp[i][i+1] = i --> always guess the smaller;
        
        for(int len=2; len <= n; len++){
            for(int i=1; i+len-1 <=n; i++){
                int j = i + len -1;
                int tmp = INT_MAX;
                for(int k=i+1; k<j; k++){
                    int guess = k + max(dp[i][k-1], dp[k+1][j]); //choose worse case when k is not the answer between [i,j]
                    tmp = min(tmp, guess); // we're smart enough to choose the best guess value
                }
                dp[i][j] = j == i+1 ? i : tmp;
            }
        }
        
        return dp[1][n];
    }
};
