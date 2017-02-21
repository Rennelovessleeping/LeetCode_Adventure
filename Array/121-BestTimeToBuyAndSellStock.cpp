/**************************************************************************
 * File Name : 121-BestTimeToBuyAndSellStock.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-12-2016
 *
 * Last Modified : Mon Feb 20 22:50:16 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Recursion formula(slow)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size()<2) return 0;
        int maxP = 0;
        for(int i=1;i<prices.size();i++){
            maxP = prices[i]-prices[0] >= maxP ? prices[i]-prices[0] : maxP;
        }
        
        vector<int> subvec (prices.begin()+1, prices.end()) ;
        return maxP >= maxProfit(subvec) ?  maxP : maxProfit(subvec);
    }
};

// Search for the min price from left
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxPro = 0;
        int minPrice = INT_MAX;
        
        for(int i=0;i<prices.size();i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        
        return maxPro;
    }
};

// Search for the max from right;
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxPro = 0;
        int maxPrice = INT_MIN;
        
        for(int i=prices.size()-1;i>=0;i--){
            maxPrice = max(maxPrice, prices[i]);
            maxPro = max(maxPro, maxPrice-prices[i]);
        }
        
        return maxPro;
    }
};

// Kadane's Algorithm for max subarray problem
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Kadane's Algorithm
        
        int maxPro = 0, maxAccumDiff = 0;
        
        for(int i=1;i<prices.size();i++){
            
            maxAccumDiff = max(0, maxAccumDiff += prices[i]-prices[i-1]); // reach at a new minimum maxAccumDiff
            maxPro = max(maxPro, maxAccumDiff);
        }
        
        return maxPro;
    }
};
