/**************************************************************************
 * File Name : 486-PredictTheWinner.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-04-2017
 *
 * Last Modified : Sun Apr  9 18:45:44 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> presum(n+1,0);
        for(int i=1; i<=n; i++) presum[i] = presum[i-1] + nums[i-1];
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //Initialization
        for(int i=0; i<n; i++) dp[i][i] = nums[i];
        
        //update dp table;
        for(int len = 2; len<=n; len++) {
            for(int i = 0; i+len<=n; i++) {
                int j = i+len-1;
                int rangesum = presum[j+1] - presum[i];
                dp[i][j] = max(rangesum - dp[i+1][j], rangesum - dp[i][j-1]);
            }
        }
        //cout << dp[0][n-1] << "," << presum[n]/2 << endl;
        return dp[0][n-1] >= presum[n]/2.0;
    }
};
