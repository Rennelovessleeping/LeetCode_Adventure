/**************************************************************************
 * File Name : 514-FreedomTrail.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-04-2017
 *
 * Last Modified : Mon Apr 24 20:33:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int ksize = key.size();

        vector<vector<int>> mp(26); // Index map of the ring
        for(int i=0; i<n; i++) mp[ring[i]-'a'].push_back(i); 
        
        
        // one can also update a dp table dp[ksize+1][n]:
        // dp[i][j] : min dist to key[i-1] that ends at ring[j]
        // if key[i-1] != ring[j], dp[i][j] = INT_MAX
        vector<int> dp(n, INT_MAX); // dp[j] min dist to reach current key[i] that ends at ring[j]
        dp[0] = 0;
        vector<int> startIdx(1,0);

        
        for(int i=1; i<=ksize; i++) {
            vector<int> next_dp(n, INT_MAX);
            for(int j:mp[key[i-1]-'a']) {
                for(auto k:startIdx) {
                    int minDist = min((j-k+n)%n, (k-j+n)%n) + dp[k];
                    next_dp[j] = min(next_dp[j], minDist);
                }
            }
            startIdx = mp[key[i-1]-'a'];
            dp.swap(next_dp);
        }
        
        int res = INT_MAX;
        for(int i=0; i<n; i++) res = min(res, dp[i]);
        
        return res + ksize;
    }
};
