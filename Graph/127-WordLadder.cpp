/**************************************************************************
 * File Name : 127-WordLadder.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-02-2017
 *
 * Last Modified : Wed Feb 15 20:38:37 2017
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
