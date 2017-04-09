/**************************************************************************
 * File Name : 471-EncodeStringWithShortestLength.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-04-2017
 *
 * Last Modified : Sat Apr  8 14:17:05 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Bottom up solution
class Solution {
public:
    string encode(string s) {
        int n = s.length();
        vector<vector<string>> dp(n, vector<string> (n,"")); 
        // dp[i][j]: encoded form of s.substr(i, j-i+1);
        // dp[i][i] == s[i];
        
        for(int len=1; len<=n; len++) {
            for(int i=0; i+len-1 < n; i++){
                int j= i+len-1;
                dp[i][j] = s.substr(i, len);
                for(int k=i; k<j; k++) {
                    string left = dp[i][k], right = dp[k+1][j];
                    if(left.size() + right.size() < dp[i][j].size()) dp[i][j] = left + right;
                }
                
                string tmp = collapse(s, dp, i, j);
                if(tmp.size() < dp[i][j].size()) dp[i][j] = tmp;
            }
        }
        
        return dp[0][n-1];
    }
    
    
    string collapse(string s, vector<vector<string>>& dp, int i, int j) {
        string tmp = s.substr(i, j-i+1);
        size_t pos = (tmp+tmp).find(tmp, 1);
        if(pos == tmp.size()) return tmp;
        return to_string(tmp.size()/pos) + "[" + dp[i][i+pos-1] + "]";
    }
    
};
