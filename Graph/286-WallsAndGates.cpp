/**************************************************************************
 * File Name : 286-WallsAndGates.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-02-2017
 *
 * Last Modified : Wed Feb 15 23:25:28 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();
        if(n == 0) return;
        
        int dist = 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j) {
                if(rooms[i][j] ==0) q.push({i, j});
            }
        }
        
        while(!q.empty()){
            int len = q.size();
            for(int k=0; k<len; k++){
                int i = q.front().first, j = q.front().second;
                q.pop();
                
                if(i>0 && rooms[i-1][j] == INT_MAX) {
                    rooms[i-1][j] = rooms[i][j] + 1;
                    q.push({i-1, j}); // Label before put in queue! Otherwise the same room might be chosen by two gates
                }
                if(i+1<m && rooms[i+1][j] == INT_MAX) {
                    rooms[i+1][j] = rooms[i][j] + 1;
                    q.push({i+1, j}); 
                }
                if(j>0 && rooms[i][j-1] == INT_MAX) {
                    rooms[i][j-1] = rooms[i][j] + 1;
                    q.push({i, j-1}); 
                }
                if(j+1<n && rooms[i][j+1] == INT_MAX) {
                    rooms[i][j+1] = rooms[i][j] + 1;
                    q.push({i, j+1}); 
                }
            }
            //dist++;
        }
        

    }

};
