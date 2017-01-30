/**************************************************************************
 * File Name : 499-TheMazeII.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-01-2017
 *
 * Last Modified : Mon Jan 30 15:29:13 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        
        int m = maze.size(), n = maze[0].size();
        queue<pair<vector<int>, string>> q;
        q.push(make_pair(ball, ""));
        
        while(!q.empty()){
            pair<vector<int>, string> cur = q.front(); 
            int i;
            cout << cur.second << endl;
            // search down
            if(cur.second=="" || cur.second.back()!='u'){
                for(i=cur.first[0]; i<m && maze[i][cur.first[1]]!=1;i++){
                    if (i==hole[0] && cur.first[1]==hole[1]) return cur.second + "d";
                }
                
                if(i!= cur.first[0]+1) q.push(make_pair(vector<int>{i-1,cur.first[1]}, cur.second+"d"));
            }
            
            // search left
            if(cur.second=="" || cur.second.back()!='r'){
                for(i=cur.first[1];i>=0 && maze[cur.first[0]][i]!=1;i--){
                    if (cur.first[0]==hole[0] && i==hole[1]) return cur.second + "l";
                }
                if(i!= cur.first[1]-1) q.push(make_pair(vector<int> {cur.first[0],i+1}, cur.second+"l"));
            } 
            
            // search right
            if(cur.second =="" || cur.second.back()!='l'){
                for(i=cur.first[1]; i<n && maze[cur.first[0]][i]!=1;i++){
                    if (cur.first[0] == hole[0] && i == hole[1]) return cur.second + "r";
                }
                if(i!=cur.first[1]+1) q.push(make_pair(vector<int>{cur.first[0], i-1}, cur.second+"r"));
            }
            
            // search up
            if(cur.second=="" || cur.second.back()!='d'){
                for(i=cur.first[0]; i>=0 && maze[i][cur.first[1]]!=1;i--){
                    if(i==hole[0] && cur.first[1]==hole[1]) return cur.second + "u";
                }
                
                if(i!=cur.first[0]-1) q.push(make_pair(vector<int>{i+1,cur.first[1]}, cur.second+"u"));
            }
            
            q.pop();
        }
        
        return "impossible";
        
    }
    
};
