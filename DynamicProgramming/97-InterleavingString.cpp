/**************************************************************************
 * File Name : 97-InterleavingString.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-04-2017
 *
 * Last Modified : Sun Apr  2 13:17:05 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length();
        if(len1 + len2 != s3.length()) return false;
        
        // Initialization
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        // dp[i][j] whether first i char in s1 and j char in s2 matches s3.substr(0, i+j)
        dp[0][0] = true;
        
        for(int i=1; i<=len1; i++) dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for(int i=1; i<=len2; i++) dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        
        // Update dp table
        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        
        return dp[len1][len2];
    }
};
