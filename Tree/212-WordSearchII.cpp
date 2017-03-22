/**************************************************************************
 * File Name : 212-WordSearchII.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-03-2017
 *
 * Last Modified : Tue Mar 21 19:15:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    struct TrieNode{
        TrieNode *next[26];
        bool isWord;
        TrieNode() : isWord(false) {
            fill_n(next, 26, nullptr);
        }
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = m ? board[0].size() : 0;
        TrieNode *root = constructTrie(words);
        unordered_set<string> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                string path = "";
                dfs(board, root, visited, res, path, i, j);
            }
        }
        
        return vector<string> (res.begin(), res.end());
    }
    
    TrieNode* constructTrie(const vector<string>& words){
        TrieNode* root = new TrieNode();
        for(const auto& word:words){
            TrieNode* p = root;
            for(int i=0; i<word.size(); i++){
                if(!p->next[word[i]-'a']) p->next[word[i]-'a'] = new TrieNode();
                p = p->next[word[i]-'a'];
            }
            p->isWord = true;
        }
        return root;
    }
private:
    int m, n;
    void dfs(const vector<vector<char>>& board, TrieNode* p, vector<vector<bool>>& visited, unordered_set<string>& res, string& path, int i, int j){
        
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j]) return;
        if( !p->next[board[i][j]-'a'] ) return;
        
        visited[i][j] = true;
        path += board[i][j];
        p = p->next[board[i][j]-'a'];
        if(p->isWord) res.insert(path);
        dfs(board, p, visited, res, path, i-1, j);
        dfs(board, p, visited, res, path, i+1, j);
        dfs(board, p, visited, res, path, i, j-1);
        dfs(board, p, visited, res, path, i, j+1);
        
        visited[i][j] = false;
        path.pop_back();
    }
};
