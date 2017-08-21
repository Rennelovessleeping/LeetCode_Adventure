/**************************************************************************
 * File Name : 650-2KeysKeyboard.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-08-2017
 *
 * Last Modified : Mon Aug 21 15:23:44 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,0);
        
        for(int i=2; i<=n; i++) {
            dp[i] = i; // copy all for then first option, then keep pasting
            for(int j=i-1; j>1; j--) {
                if(i%j == 0) {
                    dp[i] = dp[j] + i/j;
                    break; // Greedy search for max factor j;
                }
            }
        }
        
        return dp[n];
    }
};
