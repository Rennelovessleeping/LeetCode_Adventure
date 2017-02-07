/**************************************************************************
 * File Name : 79-WordSearch.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-02-2017
 *
 * Last Modified : Mon Feb  6 23:15:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Backtracing solution
ass Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        if(m == 0) return false;
        n = board[0].size();
        if(n == 0) return false;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (search(board, word, visited, i, j)) return true;
            }
        }
        
        return false;
    }
    
private:
    int m,n;
    
    bool search(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j){
        
        if(word.length() == 0) return true;
        if( i<0 || i>=m || j<0 || j >=n || visited[i][j]) return false;
        
        if(board[i][j] == word[0]){
            visited[i][j] = true;
            if ( search(board, string (word.begin()+1, word.end()), visited, i-1, j)
                || search(board, string (word.begin()+1, word.end()), visited, i+1, j)
                || search(board, string (word.begin()+1, word.end()), visited, i, j-1)
                || search(board, string (word.begin()+1, word.end()), visited, i, j+1) 
            ) return true;
            visited[i][j] = false;
        }
        
        return false;
    }
    
};

