/**************************************************************************
 * File Name : 354-RussianDollEnvelopes.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-04-2017
 *
 * Last Modified : Sun Apr  9 18:58:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        
        vector<int> dp(n, 1);
        int res = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        
        return res;
    }
};
