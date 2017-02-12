/**************************************************************************
 * File Name : 10-RegularExpressionMatching.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-02-2017
 *
 * Last Modified : Sun Feb 12 13:53:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Straightforward recursive solution
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        
        if(p[1] == '*'){
            return isMatch(s, p.substr(2)) || ( !s.empty() && (p[0]=='.' || p[0] == s[0]) && isMatch(s.substr(1),p) );
            // The latter case gaurantees that the wildcard in p matches all the repeating leading char in s;
        }
        else{
            return  !s.empty() && (p[0]=='.' || p[0] == s[0]) && isMatch(s.substr(1), p.substr(1));
        }
            
    }
};

// DP solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true; // empty matches empty;
        // for(int i=1;i<m+1;i++) dp[i][0] = false; // empty doesnt match string with finite length; 
        for(int i=1;i<n+1;i++){
            dp[0][i] = i>1 && p[i-1] == '*' && dp[0][i-2]; // only substring ending up with '*' can possibly match empty 
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1] != '*'){
                    dp[i][j] = (p[j-1] == s[i-1] || p[j-1] == '.') && dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-2] || (p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j];
                }
                
            }
        }
        
        return dp[m][n];
    }
};
