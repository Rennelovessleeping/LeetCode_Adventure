/**************************************************************************
 * File Name : 651-4KeysKeyboard.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-08-2017
 *
 * Last Modified : Mon Aug 21 15:24:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
	public:
    int maxA(int N) {
	        vector<int> dp(N+1, 0);
	        
	        for(int i=1; i<=N; i++) {
			            dp[i] = i;
			            for(int j=1; j<=i-3; j++) {
						                dp[i] = max(dp[i], dp[j]*(i-j-1));
						            }
			        }
	        
	        return dp[N];
	    }
};
