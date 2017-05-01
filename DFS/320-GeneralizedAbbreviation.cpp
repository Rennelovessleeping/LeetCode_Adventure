/**************************************************************************
 * File Name : 320-GeneralizedAbbreviation.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 12:22:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(res, word, 0, "", 0);
        return res;
    }
    
    void dfs(vector<string>& res, const string& word, int pos, string path, int count) {
        if(pos == word.size()) {
            res.push_back(count>0 ? path+to_string(count): path);
            return;
        }
        
        // Abbreviate the word[pos]
        dfs(res, word, pos+1, path, count+1);
        
        // Keep the word[pos]
        dfs(res, word, pos+1, path + (count>0 ? to_string(count) : "") + word[pos], 0);
    }
};

