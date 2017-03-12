/**************************************************************************
 * File Name : 140-WordBreakII.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-03-2017
 *
 * Last Modified : Sat Mar 11 23:49:59 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution with memorization
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(mp.find(s) != mp.end()) return mp[s];
        vector<string> res;
        
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) res.push_back(s);
        
        for(int i=1; i<s.size(); i++){
            string word = s.substr(i);
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
                string rem = s.substr(0,i);
                vector<string> prev = combine(wordBreak(rem, wordDict), word);
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        
        mp[s] = res;
        return res;
    }
private:
    unordered_map<string, vector<string>> mp;
    vector<string> combine(vector<string> prev, string word){
        
        for(auto& pre:prev){
            pre += ' ' + word;
        }
        
        //for(int i=0; i<prev.size(); i++) prev[i] += ' ' + word;
        return prev;
    }
};

// Direct DFS solution got TLE:
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string word = "";
        dfs(s, wordDict, 0, "", word, res, 0);
        return res;
        
    }
private:
    void dfs(string& s, vector<string>& wordDict, int pos, string path, string& word, vector<string>& res, int wordCnt){
        if(pos == s.size() && path.size() == s.size() + wordCnt) res.push_back(path.substr(0, path.size()-1));
        if(pos > s.size()) return;
        
        word += s[pos];
        if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end()){
            string tmp = "";
            dfs(s, wordDict, pos+1, path + word + ' ', tmp, res, wordCnt+1);
        }
        dfs(s, wordDict, pos+1, path, word, res, wordCnt);
        
    }
};
