/**************************************************************************
 * File Name : 499-TheMazeII.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-01-2017
 *
 * Last Modified : Mon Jan 30 18:17:50 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        
        search(maze, ball, hole, 0, "");
        //while(!res.empty()) {cout << res.top().first << ", "<< res.top().second << endl; res.pop();}
        return res.empty() ? "impossible" : res.top().second;
    }
    
private:
    
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> res;
    vector<vector<int>> visited;
    void search(vector<vector<int>> maze, vector<int>ball, vector<int>& hole, int dist, string path){
        if(!res.empty() && path.size() >= res.top().first) return;
        cout << ball[0] << "," << ball[1] << "---" << path << endl;
        int m = maze.size(), n = maze[0].size(), i;
        // search down
        if(path.empty() || path.back()!='u'){
            for(i=ball[0]; i<m && maze[i][ball[1]]!=1;i++){
                if (i==hole[0] && ball[1]==hole[1]) {
                    res.push(make_pair(dist + i-ball[0], path + "d"));
                    return;
                }
            }
            
            if(i!= ball[0]+1) {
                search(maze, vector<int>{i-1, ball[1]}, hole, dist+i-1-ball[0], path + "d");
            }
        }
            
        // search left
        //cout << "search left: "<< ball[0] << ", " <<ball[1] << endl;
        if(path.empty() || path.back()!='r'){
            for(i=ball[1];i>=0 && maze[ball[0]][i]!=1;i--){
                if (ball[0]==hole[0] && i==hole[1]) {
                    res.push(make_pair(ball[1]-i, path + "l"));
                    return;
                }
            }
            if(i!= ball[1]-1) {
                search(maze, vector<int>{ball[0],i+1}, hole, dist+ball[1]-i-1, path+"l");
            }
        } 
            
        // search right
        if(path.empty() || path.back()!='l'){
            for(i=ball[1]; i<n && maze[ball[0]][i]!=1;i++){
                if (ball[0] == hole[0] && i == hole[1]) {
                    res.push(make_pair( dist+i-ball[1], path + "r"));
                    return;
                }
            }
            if(i!=ball[1]+1) {
                search(maze, vector<int>{ball[0], i-1}, hole, dist+i-1-ball[1], path+"r");
            }
        }
            
        // search up
        if(path.empty() || path.back()!='d'){
            for(i=ball[0]; i>=0 && maze[i][ball[1]]!=1;i--){
                if(i==hole[0] && ball[1]==hole[1]) {
                    res.push(make_pair(dist+ball[0]-i, path + "u"));
                    return;
                }
            }
                
            if(i!=ball[0]-1){
                search(maze, vector<int>{i+1,ball[1]}, hole, dist+ball[0]-i-1, path+"u");
            }
        }
        
    } // end of search
    
};


