/**************************************************************************
 * File Name : 127-WordLadder.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-02-2017
 *
 * Last Modified : Sun Oct 22 17:48:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        vector<bool> visited(wordList.size(), false);
        queue<string> toVisit;
        toVisit.push(beginWord);
        int dist = 1; // beginWord is not in wordList, so to achieve the transformation, we need at least two steps;
        
        while(!toVisit.empty()){
            int len = toVisit.size();
            for(int i=0; i<len;i++){
                string word = toVisit.front();
                if(word == endWord) return dist;
                toVisit.pop();
                for(int j=0; j<wordList.size(); j++){
                    if(!visited[j] && isTransform(word, wordList[j])){
                        visited[j] = true;
                        toVisit.push(wordList[j]);
                    }
                }
            }
            dist++;
        }
       
       return 0;
    }
    
private:
    bool isTransform(string& word1, string& word2){
        int diff = 0;
        for(int i=0; i<word1.size();i++) {
            if (word1[i] != word2[i]) diff++;
        }
        return diff == 1;
    }
    
};

// Bidrectional BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), beginSet, endSet;
        if(!dict.count(endWord)) return 0;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        
        int res = 1;
        while(!beginSet.empty() && !endSet.empty()) {
            if(beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);;
            }
            
            unordered_set<string> tmpSet;
            res++;
            for(auto it = beginSet.begin(); it != beginSet.end(); it++) {
                string cur = *it;
                for(int i=0; i<cur.size(); i++) {
                    char temp = cur[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        cur[i] = ch;
                        if(endSet.count(cur)) return res; // when there is a collision
                        auto tmp_it = dict.find(cur);
                        if(tmp_it != dict.end()) {
                            dict.erase(cur);
                            tmpSet.insert(cur);
                        }
                    }
                    cur[i] = temp;
                }
            }
            swap(beginSet, tmpSet);
        }
        
        return 0;
    }
};
