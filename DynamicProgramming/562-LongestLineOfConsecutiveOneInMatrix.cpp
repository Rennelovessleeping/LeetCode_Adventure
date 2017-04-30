/**************************************************************************
 * File Name : 562-LongestLineOfConsecutiveOneInMatrix.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 12:10:18 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m = M.size(), n = m ? M[0].size() : 0;
        vector<vector<int>> dp(n, vector<int>(4, 0));
        // 0 - horizontal line
        // 1 - diagonal
        // 2 - vertical
        // 3 - antidiagonal
        int res = 0;
        
        for(int i=0; i<m; i++) {
            vector<vector<int>> cur(n, vector<int>(4, 0));
            for(int j=0; j<n; j++) {
                if(M[i][j] == 0) continue;
                for(int k=0; k<4; k++) cur[j][k] = 1;
                
                if(j>0) cur[j][0] = cur[j-1][0] + 1; // horizontal
                if(i>0 && j>0) cur[j][1] = dp[j-1][1] + 1; // diagonal
                if(i>0) cur[j][2] = dp[j][2] + 1; // vertical
                if(i>0 && j+1 < n) cur[j][3] = dp[j+1][3] + 1; // antidiagonal
                
                res = max(res, max(cur[j][0], cur[j][1]));
                res = max(res, max(cur[j][2], cur[j][3]));
            }
            dp.swap(cur);
        }
        
        return res;
    }
};
