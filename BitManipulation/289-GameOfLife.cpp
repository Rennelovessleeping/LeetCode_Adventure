/**************************************************************************
 * File Name : 289-GameOfLife.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-02-2017
 *
 * Last Modified : Tue Feb  7 18:59:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// In place solution using the second bit of board[i][j] to record its new status
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        if(m==0) return;
        int n= board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int countOne = -board[i][j];
                
                for(int ii=max(0,i-1);ii<min(m,i+2);ii++){
                    for(int jj=max(0,j-1);jj<min(n,j+2);jj++){
                        if(board[ii][jj] & 1) countOne++;
                    }
                }
                
                if((countOne | board[i][j]) ==3) board[i][j] |= 2;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) board[i][j] >>= 1;
        }
        
    }
};


