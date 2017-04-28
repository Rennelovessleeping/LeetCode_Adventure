/**************************************************************************
 * File Name : 132-PalindromePartitioningII.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-04-2017
 *
 * Last Modified : Thu Apr 27 21:29:53 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        
        // Initialization;
        vector<int> dp(n+1, 0); // dp[i] --- min cuts s.substr(0,i) needs
        for(int i=0; i<=n; i++) dp[i] = i-1; // dp[0] = -1;
        
        for(int i=0; i<n; i++) {
            for(int len = 0; i-len >= 0 && i+len < n && s[i-len] == s[i+len]; len++) { // odd 
                dp[i+len+1] = min(dp[i+len+1], 1+dp[i-len]);
            }
            
            for(int len = 1; i-len+1 >=0 && i+len < n && s[i-len+1] == s[i+len]; len++) { // even
                dp[i+len+1] = min(dp[i+len+1], 1+dp[i-len+1]);
            }
        }
        return dp[n];
    }
};
