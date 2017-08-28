/**************************************************************************
 * File Name : 634-FindtheDearangementOfAnArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-08-2017
 *
 * Last Modified : Sun Aug 27 22:50:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    const int mod = pow(10, 9) + 7;
    int findDerangement(int n) {
        vector<int> dp(n+1);
        dp[0] = 1, dp[1] = 0;
        for(int i=2; i<=n; i++) {
            dp[i] = ((i-1L) * ((dp[i-1] + dp[i-2])) % mod) % mod;
        }
        return dp[n];
    }
};
