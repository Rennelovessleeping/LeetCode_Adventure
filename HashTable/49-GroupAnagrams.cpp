/**************************************************************************
 * File Name : 49-GroupAnagrams.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-02-2017
 *
 * Last Modified : Wed Feb  8 20:02:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, multiset<string>> map;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++){
            string t = strs[i];
            sort(t.begin(), t.end());
            map[t].insert(strs[i]);
        }
        
        for(auto x:map){
            res.push_back(vector<string> (x.second.begin(), x.second.end()));
        }
        
        return res;
    }
    
};


// Brute force solution fails at the last test case;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<bool> visited(strs.size(), false);
        vector<vector<string>> res;
        
        for(int i=0; i<strs.size();i++){
            if(visited[i]) continue;
            visited[i] = true;
            vector<string> tmp {strs[i]};
            for(int j=0;j<strs.size();j++){
                if(visited[j]) continue;
                if(isAnagrams(strs[i], strs[j])) {
                    //cout << strs[i] << ", " << strs[j] << endl;
                    tmp.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            res.push_back(tmp);
        }
        
        return res;
        
    }
    
private:
    bool isAnagrams(string& s, string& t){
        if(s.size() != t.size()) return false;
        
        int map[128] = {0};
        //vector<int> map(128,0);
        int counter = t.size();
        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            counter -= (map[t[i]]-- > 0);
        }
        return counter == 0;
    }
    
};
