/**************************************************************************
 * File Name : 174-DungeonGame.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-04-2017
 *
 * Last Modified : Sun Apr  9 18:24:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = m ? dungeon[0].size() : 0;
        
        // Initialization
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX)); 
        // min hp one needs to reach the princess room from room dungeon[i][j];
        
        dp[m-1][n] = dp[m][n-1] = 1; // for the target room
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) { // update from bottom right to top left;
                int minhp = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = minhp <= 0 ? 1 : minhp;
            }
        }
        
        return dp[0][0];
    }
};
