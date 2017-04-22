/**************************************************************************
 * File Name : 255-ShortestWordDistanceII.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-04-2017
 *
 * Last Modified : Sat Apr 22 14:41:22 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i=0; i<words.size(); i++) mp[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for(int i=0, j=0; i<mp[word1].size() && j<mp[word2].size();) {
            res = min(res, abs(mp[word1][i] - mp[word2][j]));
            mp[word1][i] < mp[word2][j] ? i++ : j++;
        }
        
        return res;
    }
    
private:
    unordered_map<string, vector<int>> mp; // word: vector of idx
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
