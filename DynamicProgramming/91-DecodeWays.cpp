/**************************************************************************
 * File Name : 91-DecodeWays.cpp
 *
 * Purpose :
 *
 * Creation Date : 10-02-2017
 *
 * Last Modified : Fri Feb 10 12:10:37 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Pay atttention to zeros!
class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        if(n==0 || s[0]=='0') return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            if(s[i-1] == '0' && s[i-2]-'0' > 3) return 0;
            int tmp = (s[i-2]-'0')*10 + s[i-1]-'0';
            dp[i] = (s[i-1]=='0'? 0: dp[i-1]) + (tmp >= 10 && tmp <=26  ? dp[i-2] : 0 );
            cout << i << ", " << dp[i] << endl;
        }
        return dp[n];
    }
};

// Conciser Solution
class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        if(n==0 || s[0]=='0') return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            if(s[i-1] != '0') dp[i] = dp[i-1];
            if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] -'0' <= 6) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
