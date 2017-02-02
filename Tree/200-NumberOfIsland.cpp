/**************************************************************************
 * File Name : 200-NumberOfIsland.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-02-2017
 *
 * Last Modified : Wed Feb  1 19:42:26 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if(m==0) return 0;
        n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Navigate grid
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    islands++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        
        return islands;
    }

private:
    int m,n;
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        if( i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i, j-1);
        dfs(grid, visited, i, j+1);
        
    }
    
};


