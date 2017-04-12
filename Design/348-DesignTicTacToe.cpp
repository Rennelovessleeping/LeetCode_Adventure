/**************************************************************************
 * File Name : 348-DesignTicTacToe.cpp
 *
 * Purpose :
 *
 * Creation Date : 10-04-2017
 *
 * Last Modified : Mon Apr 10 22:05:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<int> (n,0);
        cols = vector<int> (n,0);
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int incr = player == 1 ? 1 : -1;
        
        rows[row] += incr;
        cols[col] += incr;
        if(row == col) diag += incr;
        if(row + col == n-1) antidiag += incr;
        
        if(abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(antidiag) == n) return player;
        
        return 0;
    }
    
private:
    vector<int> rows, cols;
    int diag, antidiag, n;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
