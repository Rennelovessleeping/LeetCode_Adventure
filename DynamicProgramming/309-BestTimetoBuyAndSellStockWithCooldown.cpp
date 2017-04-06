/**************************************************************************
 * File Name : 309-BestTimetoBuyAndSellStockWithCooldown.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-04-2017
 *
 * Last Modified : Wed Apr  5 22:31:59 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        vector<int> buy(n+1, 0), sell(n+1, 0);
        // buy[i] : up to first i days, highest buy in price;
        // sell[i] : up to first i days, highest sell out price;
        buy[0] = INT_MIN; buy[1] = -prices[0];
        //sell[0] = 0; sell[1] = 0;
        
        for(int i=2; i<=n; i++){
            buy[i] = max(buy[i-1], sell[i-2]-prices[i-1]); // cooldown here;
            sell[i] = max(sell[i-1], buy[i-1]+prices[i-1]);
            //cout << buy[i] << ", " << sell[i] << endl;
        }
        return sell[n];
    }
};
