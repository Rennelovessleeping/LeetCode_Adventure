/**************************************************************************
 * File Name : 322-CoinChange.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-03-2017
 *
 * Last Modified : Fri Mar 31 21:51:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1); // dont use INT_MAX here to avoid overflow due to dp[i-coins[j] + 1]
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(i>=coins[j]) dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        
        //for(auto n:dp) cout << n << endl;
        
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

