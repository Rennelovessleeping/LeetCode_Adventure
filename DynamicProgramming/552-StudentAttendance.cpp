/**************************************************************************
 * File Name : 552-StudentAttendance.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-04-2017
 *
 * Last Modified : Fri Apr 28 21:10:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int checkRecord(int n) {
        int mod = pow(10,9)+7;
        
        // vector<vector<int>> dp(2, vector<int>(3,1));
        int dp[2][3] = {{1,1,1},{1,1,1}};
        
        // dp[i][j][k] : maximum # of rewardable sequence with length of i that contains at most j 'A' and trailing k 'L'
        // dp[0] = {{1,1,1}, {1,1,1}};
        
        for(int i=1; i<=n; i++) {
            // vector<vector<int>> cur(2, vector<int>(3));
            int cur[2][3];
            for(int j=0; j<2; j++) {
                for(int k=0; k<3; k++) {
                    int val = dp[j][2]; // Add 'P'
                    if(j > 0) val = (val + dp[j-1][2]) % mod; // Add 'A'
                    if(k > 0) val = (val + dp[j][k-1]) % mod; // Add 'L': e.g. when k=2 --> k-1=1; k=1 --> k-1=0 
                    cur[j][k] = val;
                }
            }
            
            copy(&cur[0][0], &cur[0][0]+6, &dp[0][0]);
            /*
            for(int j=0; j<2; j++){
                for(int k=0; k<3; k++) dp[j][k] = cur[j][k];
            }
            */
        }
        
        return dp[1][2];
    }
};
