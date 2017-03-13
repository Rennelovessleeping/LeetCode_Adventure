/**************************************************************************
 * File Name : 317-ShortestDistanceFromAllBuilding.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-03-2017
 *
 * Last Modified : Mon Mar 13 14:32:09 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// use auxiliary walk var to avoid using visited matrix every time launching BFS
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        vector<vector<int>> totalDist(m, vector<int>(n, 0));
        
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int walk = 0, res; 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 1) continue;
                vector<vector<int>> dist(m, vector<int>(n, 0));
                queue<pair<int, int>> q;
                q.push({i, j});
                res = -1;
                
                while(!q.empty()){
                    int i = q.front().first, j = q.front().second;
                    q.pop();
                    for(auto dir:directions){
                        int x = i + dir.first, y = j + dir.second;
                        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]!=walk) continue;
                        grid[x][y]--;
                        dist[x][y] = dist[i][j] + 1;
                        totalDist[x][y] += dist[x][y];
                        q.push({x, y});
                        if(res < 0 || totalDist[x][y] < res) res = totalDist[x][y];
                        //res = min(res, totalDist[x][y]);
                    }
                }
                walk--;
            }
        }
        
        return res;
    }
};
