/**************************************************************************
 * File Name : LonestCommonSubstring.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-09-2017
 *
 * Last Modified : Thu Sep 28 14:02:36 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
int LongestCommonSubstring(string s, string t) {
    int m = s.size(), n = t.size(), res = 0;

    vector<int> dp(m+1, vector<int>(n+1, 0)); // dp[i][j] = maxLen of common substring in s.substr(0,i) and t.substr(0,j)
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            res = max(dp[i][j], res);
        }
    }

    return res;
}
