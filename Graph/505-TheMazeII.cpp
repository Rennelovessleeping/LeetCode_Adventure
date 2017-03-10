/**************************************************************************
 * File Name : 505-TheMazeII.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-03-2017
 *
 * Last Modified : Thu Mar  9 22:33:04 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = m ? maze[0].size() : 0;
        
        vector<vector<int>> visited(m, vector<int>(n, -1));
        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]] = 0;
        
        int minDist = INT_MAX;
        while(!q.empty()){
            vector<int> tmp = q.front(); 
            q.pop();
            int dist = visited[tmp[0]][tmp[1]];
            if(tmp == destination) minDist = min(dist, minDist);
            
            for(auto dir:directions){
                vector<int> nextStart = go2end(maze, tmp, dir);
                int newdist = dist + calcDist(nextStart, tmp);
                if( visited[nextStart[0]][nextStart[1]]==-1 || visited[nextStart[0]][nextStart[1]] > newdist){
                    visited[nextStart[0]][nextStart[1]] = newdist;
                    q.push(nextStart);
                }
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
    
private:
    int m, n;
    vector<int> go2end(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir){
        vector<int> des = start;
        vector<int> newdes = {des[0]+dir[0], des[1]+dir[1]};
        while(newdes[0]>=0 && newdes[0]<m && newdes[1]>=0 && newdes[1]<n && maze[newdes[0]][newdes[1]] == 0){
            des.swap(newdes);
            newdes[0] = des[0] + dir[0];
            newdes[1] = des[1] + dir[1];
        }
        return des;
    }
    
    int calcDist(vector<int> pt1, vector<int> pt2){
        return pt1[0] == pt2[0] ? abs(pt1[1] - pt2[1]) : abs(pt1[0] - pt2[0]);
    }
};
