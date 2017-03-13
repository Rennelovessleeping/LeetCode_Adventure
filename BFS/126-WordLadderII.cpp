/**************************************************************************
 * File Name : 126-WordLadderII.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-03-2017
 *
 * Last Modified : Mon Mar 13 17:29:59 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BSF --> shortest dist + build nebr table tracing from the start along shortest distance
// DFS --> construct all the path for output
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dict(wordList.begin(), wordList.end());
        //dict.insert(beginWord);
        vector<vector<string>> res;
        unordered_map<string, int> dist_mp;
        unordered_map<string, unordered_set<string>> neighbors_mp;
        int minDist = 0;
        
        //wordList.push_back(beginWord);
        bfs(beginWord, endWord, dict, dist_mp, neighbors_mp);
        vector<string> path{beginWord};
        dfs(beginWord, endWord, dist_mp, neighbors_mp, res, path);
        
        return res;
    }
    
private:
    vector<string> getNeighbors(string cur, set<string>& dict){
        vector<string> res;
        for(char ch='a'; ch<='z'; ch++){
            for(int i = 0; i<cur.size();i++){
                if(ch == cur[i]) continue;
                char tmp = cur[i];
                cur[i] = ch;
                if(dict.find(cur) != dict.end()) res.push_back(cur);
                cur[i] = tmp;
            }
        }
        // for(auto str:res) cout << str << ", " ; cout << endl;
        return res;
    }
    
    void bfs(string begin, string end, set<string>& dict, unordered_map<string, int>& dist_mp, 
        unordered_map<string, unordered_set<string>>& neighbors_mp){
            
        queue<string> q;
        q.push(begin);
        dist_mp[begin] = 0;
            
        while(!q.empty()){
            bool foundEnd = false;
            int len = q.size();
            
            for(int i=0; i<len; i++){
                string cur = q.front(); q.pop();
                vector<string> neighbors = getNeighbors(cur, dict);
                // cout << neighbors.size() << endl;
                for(auto nebr:neighbors){
                    neighbors_mp[cur].insert(nebr);
                    if(dist_mp.find(nebr) == dist_mp.end()){ // unvisited;
                        dist_mp[nebr] = dist_mp[cur] + 1;
                        if(nebr == end) {
                            foundEnd = true;
                        }
                        else q.push(nebr);
                    }
                }
                
            }
            //cout << dist << endl;
            if (foundEnd) break;
        }
    }
        
    void dfs(string begin, string end, unordered_map<string, int>& dist_mp, 
        unordered_map<string, unordered_set<string>>& neighbors_mp, vector<vector<string>>& res, vector<string>& path){
        if(begin == end) res.push_back(path);
        else{
            for(auto nebr:neighbors_mp[begin]){
                if(dist_mp[nebr] == dist_mp[begin]+1) {
                    path.push_back(nebr);
                    dfs(nebr, end, dist_mp, neighbors_mp, res, path);
                    path.pop_back();
                }
            }
        }
        
    }    
};
