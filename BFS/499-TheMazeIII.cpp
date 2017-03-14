/**************************************************************************
 * File Name : 499-TheMazeIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-03-2017
 *
 * Last Modified : Tue Mar 14 00:24:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    struct point{
        int x;
        int y;
        int dist;
        string path;
        
        point(int i, int j, int d, string p) : x(i), y(j), dist(d), path(p) {}
        bool operator < (const point& obj) const{
            return dist < obj.dist ? true: (dist == obj.dist && path < obj.path);
        }
    };
    
    struct cmp{
        bool operator() (point& l, point& r){
            //return l.dist > r.dist ? true : (l.dist == r.dist && l.path > r.path);
            return !(l < r);
        }
    };
    
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = m ? maze[0].size() : 0;
        vector<vector<point>> dist; // the visited matrix that stores both shortest path to it as well as path str
        for(int i=0; i<m; i++){
            dist.push_back(vector<point>{});
            for(int j=0; j<n; j++){
                dist[i].push_back(point(i, j, INT_MAX, ""));
            }
        }
        
        priority_queue<point, vector<point>, cmp> pq;
        pq.push(point(ball[0], ball[1], 0, ""));
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<string> dirStr = {"u", "d", "l", "r"};
        
        while(!pq.empty()){
            point p = pq.top(); pq.pop();
            //cout << p.x << ", " << p.y << "," << p.dist << ", " << p.path << endl;
            if(dist[p.x][p.y] < p) continue;
            dist[p.x][p.y] = p;
            for(int k=0; k<4; k++){
                int i = p.x, j = p.y, dist = p.dist;
                string path = p.path;
                while(i>=0 && i<m && j>=0 && j<n && maze[i][j] == 0 && (i!=hole[0] || j!= hole[1])){
                    i += dir[k][0];
                    j += dir[k][1];
                    dist++;
                }
                if(i!=hole[0] || j!=hole[1]) {
                    i -= dir[k][0];
                    j -= dir[k][1];
                    dist--;
                }
                pq.push(point(i, j, dist, path+dirStr[k]));
                //cout << i << ", " << j << "," << path + dirStr[k] << endl;
            }
            
        }

        return dist[hole[0]][hole[1]].dist == INT_MAX ? "impossible" : dist[hole[0]][hole[1]].path;
    }
};
