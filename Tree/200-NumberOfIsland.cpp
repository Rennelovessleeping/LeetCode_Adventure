/**************************************************************************
 * File Name : 200-NumberOfIsland.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-02-2017
 *
 * Last Modified : Mon Mar 20 12:13:30 2017
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


// UnionFind solution
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        vector<int> parent(m*n, 0);
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int tmp = i*n + j;
                cnt += grid[i][j] == '1';
                parent[tmp] = tmp;
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '0') continue;
                
                int cur = i*n+j;
                if(i-1>=0 && grid[i-1][j] == '1'){
                    int nebr = (i-1)*n + j;
                    if(!isConnected(parent, cur, nebr)) connect(parent, cur, nebr, cnt);
                }
                
                if(i+1<m && grid[i+1][j] == '1'){
                    int nebr = (i+1)*n + j;
                    if(!isConnected(parent, cur, nebr)) connect(parent, cur, nebr, cnt);
                }
                
                if(j-1>=0 && grid[i][j-1] == '1'){
                    int nebr = i*n + j - 1;
                    if(!isConnected(parent, cur, nebr)) connect(parent, cur, nebr, cnt);
                }
                
                if(j+1<n && grid[i][j+1] == '1'){
                    int nebr = i*n + j + 1;
                    if(!isConnected(parent, cur, nebr)) connect(parent, cur, nebr, cnt);
                }
                
            }
        }
        
        return cnt;
    }
    
private:
    bool isConnected(vector<int>& parent, int p, int c){
        while(p !=  parent[p]) p = parent[parent[p]];
        while(c !=  parent[c]) c = parent[parent[c]];
        return c == p;
    }
    
    void connect(vector<int>& parent, int p, int c, int& cnt){
        while(p !=  parent[p]) p = parent[parent[p]];
        while(c !=  parent[c]) c = parent[parent[c]];
        if (c == p) return;
        parent[c] = p;
        cnt--;
    }
    
};
