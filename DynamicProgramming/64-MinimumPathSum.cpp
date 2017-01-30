/**************************************************************************
 * File Name : 64-MinimumPathSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-01-2017
 *
 * Last Modified : Sun Jan 29 21:24:11 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { 
        int m = grid.size();
        if(m==0) return 0;
        int n = grid[0].size();
        if(n==0) return 0;
        //vector<vector<int>> minSoFar(m, vector<int>(n));
        
        // Initialization
        vector<int> pre(n);
        pre[0] = grid[0][0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + grid[0][i];
        
        for(int i=1;i<m;i++) {
            vector<int> cur(n);
            cur[0] = pre[0] + grid[i][0];
            for(int j=1;j<n;j++) {
                cur[j] = min(pre[j], cur[j-1]) + grid[i][j];
            }
            cur.swap(pre);
        }
        
        return pre[n-1];
    }
};

