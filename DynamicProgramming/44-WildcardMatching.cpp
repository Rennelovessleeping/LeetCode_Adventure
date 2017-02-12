/**************************************************************************
 * File Name : 44-WildcardMatching.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-02-2017
 *
 * Last Modified : Sun Feb 12 14:42:07 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0]= true;
        for(int j=1;j<=n;j++) dp[0][j] = p[j-1]=='*' && dp[0][j-1];
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j-1] && (p[j-1]=='?' || p[j-1]==s[i-1]);
                }
            }
        }
        return dp[m][n];
    }
};


