/**************************************************************************
 * File Name : 269-AlienDictionary.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-02-2017
 *
 * Last Modified : Fri Feb 17 22:50:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> inDegree;
        unordered_map<char, unordered_set<char>> suc; // store the successors for each char
        
        
        for(auto w:words){
            for(int i=0; i<w.length(); ++i){
                if(inDegree.find(w[i]) == inDegree.end()){
                    inDegree.insert({w[i],0});
                }
            }
        }
        
        
        for(int i=0; i<words.size()-1; ++i){ 
            string cur = words[i], next = words[i+1];
            int len = min(cur.size(), next.size());
            for(int j=0; j<len; ++j){
                if(cur[j] != next[j]){ // lexigraphical order is sorted by the first different char
                    suc[cur[j]].insert(next[j]);
                    inDegree[next[j]]++;
                    break;
                }
            }
        }
        
        //for(auto x:inDegree) cout << x.first << ", " << x.second << endl;
        cout << suc.size() << endl;
        
        //BFS serach
        string res = "";
        queue<char> q;
        for(auto x:inDegree){
            if(x.second == 0) q.push(x.first);
        }
        
        while(!q.empty()){
            char tmp = q.front();
            res += tmp;
            q.pop();
            if(!suc.empty()){
                for(auto x:suc[tmp]){
                    inDegree[x]--;
                    if(inDegree[x] == 0) q.push(x);
                }
            }
        }
        
        return res.length() == inDegree.size() ?  res : "";
        
    }
};

