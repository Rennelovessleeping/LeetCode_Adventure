/**************************************************************************
 * File Name : 188-BestTimeToBuyAndSellStockIV.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-03-2017
 *
 * Last Modified : Fri Mar 31 20:40:53 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(k >= len/2) return infinite(prices);
        vector<vector<int>> dp(k+1, vector<int>(len, 0)) ;
        
        for(int i=1; i<=k; i++) {
            int buy = -prices[0];
            for(int j=1; j<len; j++) {
                dp[i][j] = max(dp[i][j-1], prices[j]+buy);
                buy = max(buy, dp[i-1][j]-prices[j]);
            }
        }
        
        return dp[k][len-1];
    }
    
private:
    int infinite(vector<int>& prices) {
        int res = 0;
        for(int i=1; i<prices.size(); i++){
            res += max(prices[i]-prices[i-1], 0);
        }
        return res;
    }
};
