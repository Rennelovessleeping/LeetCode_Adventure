/**************************************************************************
 * File Name : 351-AndroidUnlockPattern.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-04-2017
 *
 * Last Modified : Thu Apr  6 22:09:51 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> visited(10, false);
        vector<vector<int>> skip(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = 5;
        
        int res = 0;
        for(int rem = m; rem <=n; rem++) {
            res += dfs(skip, visited, 1, rem-1) * 4;
            res += dfs(skip, visited, 2, rem-1) * 4;
            res += dfs(skip, visited, 5, rem-1);
        }
        
        return res;
    }
    
    int dfs(const vector<vector<int>>& skip, vector<bool>& visited, int pos, int rem) {
        
        if(rem == 0) return 1;
        
        visited[pos] = true;
        int res = 0;
        for(int i=1; i<=9; i++) {
            if(visited[i] || (skip[pos][i] !=0 && !visited[skip[pos][i]]) ) continue;
            res += dfs(skip, visited, i, rem-1);
        }
        
        visited[pos] = false;
        return res;
    }
};
