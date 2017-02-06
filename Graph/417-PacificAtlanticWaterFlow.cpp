/**************************************************************************
 * File Name : 417-PacificAtlanticWaterFlow.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-02-2017
 *
 * Last Modified : Sun Feb  5 20:24:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// The trick is use bit mast to take account whether a node(i, j) has not been visited(00), has been visited from Pacifit(01),
// has veen visited only from Atlantic(10) and have been visited from both oceans(11);
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        m = matrix.size();
        if(m==0) return vector<pair<int, int>> {};
        n = matrix[0].size();
        if(n==0) return vector<pair<int, int>> {};
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        for(int i=0;i<m;i++){
            dfs(matrix, visited, i, 0, INT_MIN, 1); // search from Pacific
            dfs(matrix, visited, i, n-1, INT_MIN, 2); // search from Atlantic
        }
        
        for(int i=0;i<n;i++){
            dfs(matrix, visited, 0, i, INT_MIN, 1); // search from Pacific
            dfs(matrix, visited, m-1, i, INT_MIN, 2); // search from Atlantic
        }
        
        return res;
        
    }

private:
    int m, n;
    vector<pair<int, int>> res;
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int preHeight, int ocean){
        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j] < preHeight || (visited[i][j]&ocean) == ocean) return;
        
        visited[i][j] |= ocean; // become 3 when visited from both oceans; 
        // From visited[i][j]&ocean) == ocean we know that once (i,j) is confirmed as flow candidate, 
        // it will never be visited.
        if(visited[i][j] == 3) res.push_back(make_pair(i, j));
        
        dfs(matrix, visited, i-1, j, matrix[i][j], visited[i][j]);
        dfs(matrix, visited, i+1, j, matrix[i][j], visited[i][j]);
        dfs(matrix, visited, i, j-1, matrix[i][j], visited[i][j]);
        dfs(matrix, visited, i, j+1, matrix[i][j], visited[i][j]);
        
    }
};


