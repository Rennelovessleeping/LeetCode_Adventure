/**************************************************************************
 * File Name : 37-SudokuSolver.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-04-2017
 *
 * Last Modified : Thu Apr 13 20:08:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j) {
        if(i==9) return true;
        if(j==9) return dfs(board, i+1, 0);
        if(board[i][j] != '.') return dfs(board, i, j+1);
        
        for(char val='1'; val<='9'; val++) {
            if(isValid(board, i, j, val)) {
                board[i][j] = val;
                if(dfs(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    bool isValid(const vector<vector<char>>& board, int x, int y, char val) {
        int row = x - x%3, col = y - y%3; // calculate block index
        
        for(int i=0; i<9; i++) if(board[i][y] == val) return false;
        for(int j=0; j<9; j++) if(board[x][j] == val) return false;
        
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[row+i][col+j] == val) return false;
            }
        }
        
        return true;
    }
};
