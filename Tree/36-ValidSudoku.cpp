/**************************************************************************
 * File Name : 36-ValidSudoku.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-12-2016
 *
 * Last Modified : Wed Dec 21 23:29:05 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// The checking strategy is obviously easy. Doing this through a 2d array 
// as checker is much simpler than building hashtable to record the count of
// nine digits.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rowChecker[9][9]={0}, colChecker[9][9]={0}, blockChecker[9][9] = {0};
        int i, j, k, num;
        
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                
                if(board[i][j] != '.'){
                    k = i/3*3 + j/3;
                    num = board[i][j] - '0' - 1;
                    if( rowChecker[i][num] || colChecker[j][num] || blockChecker[k][num]) {
                        return false;
                    }
                    rowChecker[i][num] = colChecker[j][num] = blockChecker[k][num] = 1;
                }
                
                
            }
        }
        
        return true;
    }
};
