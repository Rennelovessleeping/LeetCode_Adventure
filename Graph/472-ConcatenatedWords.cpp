/**************************************************************************
 * File Name : 472-ConcatenatedWords.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-03-2017
 *
 * Last Modified : Sat Mar 11 00:07:38 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solutoin: record unconcatenatable words in unorder_set
// Dont check by words, check by letters, since both "cat" and "cats" appear
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), [](string& l, string& r){return l.length() < r.length();});
        unordered_set<string> mp;
        for(int i=0; i<words.size(); i++){
            string path = "";
            if(dfs(words[i], mp, path, 0, 0)) res.push_back(words[i]);
            else mp.insert(words[i]);
        }
        return res;
    }
private:
    bool dfs(string& word, unordered_set<string>& mp, string& path, int pos, int wordNum){
        if(pos == word.length()) return mp.find(path) != mp.end() && wordNum > 0;
        path += word[pos];
        if(mp.find(path) != mp.end()){
            string tmp = "";
            if(dfs(word, mp, tmp, pos+1, wordNum+1)) return true;
        }
        return dfs(word, mp, path, pos+1, wordNum);
    }
};
