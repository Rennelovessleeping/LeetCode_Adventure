/**************************************************************************
 * File Name : 115-DistinctSubsequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-04-2017
 *
 * Last Modified : Wed Apr  5 22:55:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // dp[i][j] : how many times that t.substr(0,j) appears as distinct subsequence in s.substr(0,i);
        
        // Initialization
        for(int i=0; i<=m; i++) dp[i][0] = 1; // empty string appears once in a string with finite length
        
        // Update dp table
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        
        return dp[m][n];
    }
};
