/**************************************************************************
 * File Name : 419-BattleshipsInABoard.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 11:24:21 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        // Standard DFS will require O(mn) extra space or altered the board;
        int m = board.size(), n = m ? board[0].size() : 0;
        int res = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                // Only count the up left corner of a battleship
                if(board[i][j] == '.') continue;
                else if(i>0 && board[i-1][j] == 'X') continue;
                else if(j>0 && board[i][j-1] == 'X') continue;
                
                res++;
            }
        }
        
        return res;
    }
};
