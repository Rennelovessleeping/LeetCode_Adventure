/**************************************************************************
 * File Name : 403-FrogJump.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-04-2017
 *
 * Last Modified : Sun Apr  9 17:26:38 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp; // unit:steps
        for(int i=0; i<n; i++) dp[stones[i]] = unordered_set<int> {};
        
        dp[0].insert(1);
        
        for(int i=0; i<n; i++){
            int stone = stones[i];
            for(const auto& step:dp[stone]){
                int reach = stone + step;
                if(reach == stones.back()) return true;
                
                if(dp.find(reach) != dp.end()){
                    dp[reach].insert(step);
                    if(step-1 > 0) dp[reach].insert(step-1);
                    dp[reach].insert(step+1);
                }
            }
        }
        
        return false;
    }
};
