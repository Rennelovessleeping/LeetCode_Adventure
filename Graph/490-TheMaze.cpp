/**************************************************************************
 * File Name : 490-TheMaze.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-03-2017
 *
 * Last Modified : Thu Mar  9 17:45:44 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = m ? maze[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(maze, visited, start, destination);
    }
private:
    int m, n;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<int> start, vector<int>& destination){
        if(start == destination) return true;
        if(visited[start[0]][start[1]]) return false;
        
        visited[start[0]][start[1]] = true;
        for(auto dir:directions){
            vector<int> nextStart = go2end(maze, start, dir);
            if(nextStart != start && dfs(maze, visited, nextStart, destination)) return true; 
        }
        
        return false;
    }
    
    vector<int> go2end(vector<vector<int>>& maze, vector<int> start, pair<int, int> dir){
        vector<int> des = start;
        vector<int> newdes = {des[0]+dir.first, des[1]+dir.second};
        while(newdes[0]>=0 && newdes[0]<m && newdes[1]>=0 && newdes[1]<n && maze[newdes[0]][newdes[1]] == 0){
            des.swap(newdes);
            newdes[0] = des[0] + dir.first;
            newdes[1] = des[1] + dir.second;
        }
        
        return des;
    }
};

// BFS solution: next four end is the rollable spots along four directions
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size();
        n = m ? maze[0].size() : 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]] = true;
        
        while(!q.empty()){
            vector<int> tmp = q.front(); q.pop();
            if(tmp == destination) return true;
            
            for(auto dir : directions){
                vector<int> nextStart = go2end(maze, tmp, dir);
                if(nextStart != tmp && !visited[nextStart[0]][nextStart[1]]){
                    visited[nextStart[0]][nextStart[1]] = true;
                    q.push(nextStart);
                } 
            }
            
        }
        
        return false;
    }
    
private:
    int m, n;
    vector<int> go2end(vector<vector<int>>& maze, vector<int> start, vector<int>& dir){
        vector<int> des = start;
        vector<int> newdes = {des[0]+dir[0], des[1]+dir[1]};
        while(newdes[0]>=0 && newdes[0]<m && newdes[1]>=0 && newdes[1]<n && maze[newdes[0]][newdes[1]]==0){
            des.swap(newdes);
            newdes[0] = des[0] + dir[0];
            newdes[1] = des[1] + dir[1];
        }
        return des;
    }
};
