/**************************************************************************
 * File Name : 123-BestTimeToBuyAndSellStockIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-03-2017
 *
 * Last Modified : Fri Mar 31 20:30:10 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long sell1 = 0, sell2 = 0;
        long buy1 = INT_MIN, buy2 = INT_MIN;
        
        for(int i=0; i<prices.size(); i++){
            sell2 = max(sell2, prices[i] + buy2);
            buy2 = max(buy2, sell1-prices[i]);
            
            sell1 =  max(sell1, prices[i] + buy1); // largest profit with only one transaction
            buy1 = max(buy1, (long)-prices[i]);
            // cout << buy1 << ", " << sell1 << ", " << buy2 << ", " << sell2 << endl;
        }
        
        return sell2;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(2+1, vector<int>(n, 0));
        
        for(int i=1; i<=2; i++){
            int buy = -prices[0];
            for(int j=1; j<n; j++) {
                dp[i][j] = max(dp[i][j-1], buy + prices[j]); // max profit achieved by selling i'th stock on j'th day;
                buy = max(buy, dp[i-1][j-1] - prices[j]);
            }
        }
        
        return dp[2][n-1];
    }
};
