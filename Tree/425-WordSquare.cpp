/**************************************************************************
 * File Name : 425-WordSquare.cpp
 *
 * Purpose :
 *
 * Creation Date : 19-03-2017
 *
 * Last Modified : Sun Mar 19 23:37:07 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    struct TrieNode{
        TrieNode* next[26];
        bool isWord;
        vector<string> startWith;
        TrieNode(): isWord(false), startWith(vector<string> {}) {
            memset(next, 0, sizeof(next));
        }
        
    };
    
    TrieNode* buildTrie(const vector<string>& words){
        TrieNode* root = new TrieNode();
        for(const auto& word:words){
            TrieNode* p = root;
            for(int i=0; i<word.size(); i++){
                if(!p->next[word[i]-'a']) p->next[word[i]-'a'] = new TrieNode(); 
                p = p->next[word[i]-'a'];
                p->startWith.push_back(word);
            }
            p->isWord = true;
        }
        return root;
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        m = words.size(), n = m ? words[0].size() : 0;
        cout << m << ", " << n << endl;
        vector<vector<string>> res;
        TrieNode *root = buildTrie(words);
        for(const auto& word:words){
            vector<string> path{word};
            dfs(res, path, root, 1);
        }
        return res;
    }
    
    int m, n;
    void dfs(vector<vector<string>>& res, vector<string>& path, TrieNode* root, int level){
        if(level == n){
            res.push_back(path);
            return;
        }
        string prefix = "";
        for(int i=0; i<level;i++) {
            prefix += path[i][level];
            //cout << path[i] << ", ";
        }
        //cout << prefix << ": " << level << endl;
        
        TrieNode* p = root;
        for(const auto& ch:prefix){
            if(!p->next[ch-'a']) return;
            p = p->next[ch-'a'];
        }

        for(const auto& word: p->startWith){
            path.push_back(word);
            dfs(res, path, root, level+1);
            path.pop_back();
        }
        
    }
    
};
