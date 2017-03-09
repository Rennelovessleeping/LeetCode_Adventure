/**************************************************************************
 * File Name : 407-TrappingRainWaterII.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-03-2017
 *
 * Last Modified : Wed Mar  8 20:52:22 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Purely extention of two-pointer solution of trap water in 1D;
        // We want the min height from four boundaries, so we need to maintain a min_heap for that;
        // We need to keep track of the maxHeight in 1D, so do we in 2D 
        
        int m = heightMap.size(), n = m ? heightMap[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min_heap
        
        for(int i=0; i<m; i++){
            pq.push({heightMap[i][0], i*n});
            pq.push({heightMap[i][n-1], i*n+n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        
        for(int j=0; j<n; j++){
            pq.push({heightMap[0][j], j});
            pq.push({heightMap[m-1][j], (m-1)*n+j});
            visited[0][j] = visited[m-1][j] = true;
        }
        
        int res = 0, maxHeight = 0;
        vector<pair<int, int>> neighbors = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!pq.empty()){
            auto tmp = pq.top(); pq.pop();
            maxHeight = max(maxHeight, tmp.first);
            int i = tmp.second/n, j = tmp.second%n;
            for(auto nebr:neighbors){
                int x = i+nebr.first, y = j+nebr.second;
                if(x<0 || x>=m || y<0 || y>=n || visited[x][y]) continue;
                res += maxHeight <= heightMap[x][y] ? 0 : maxHeight - heightMap[x][y];
                visited[x][y] = true;
                pq.push({heightMap[x][y], x*n+y});
            }
        }
        return res;
        
    }
};
