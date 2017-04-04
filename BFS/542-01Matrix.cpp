/**************************************************************************
 * File Name : 542-01Matrix.cpp
 *
 * Purpose :
 *
 * Creation Date : 04-04-2017
 *
 * Last Modified : Tue Apr  4 14:51:52 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] != 0) continue;
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
        
        vector<vector<int>> directions {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        while(!q.empty()){
            int i = q.front().first, j = q.front().second; 
            q.pop();
            
            int cur_dist = dist[i][j];
            for(const auto& dir:directions) {
                int x = i+dir[0], y = j+dir[1];
                if(x<0 || x>=m || y<0 || y>=n || dist[x][y] != -1) continue;
                dist[x][y] = dist[i][j] + 1;
                q.push({x, y});
            }
        }
        
        return dist;
    }
};
