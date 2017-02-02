/**************************************************************************
 * File Name : 130-SurroundedRegions.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-02-2017
 *
 * Last Modified : Wed Feb  1 20:37:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m==0) return;
        n = board[0].size();
        if(n==0) return;
        
        // check the left and right boundary:
        for(int i=0;i<m;i++){
            if( board[i][0]=='O') bfsBoundary(board, i, 0);
            if( board[i][n-1]=='O') bfsBoundary(board, i, n-1);
        }
        
        // check the up and bottom boundary:
        for(int i=0;i<n;i++){
            if(board[0][i] == 'O') bfsBoundary(board, 0, i);
            if(board[m-1][i] == 'O') bfsBoundary(board, m-1,i);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (board[i][j] == 'B') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
    }

private:
    int m, n;
    void bfsBoundary(vector<vector<char>>& board, int i, int j){
        //(i,j) are the points to be explored;
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        board[i][j] = 'B';
        
        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();
            vector<pair<int, int>> neighbors{{i-1, j},{i+1, j},{i, j-1},{i, j+1}};
            
            for(auto neigh:neighbors){
                int x = neigh.first, y = neigh.second;
                if(x>=0 && x<m && y>=0 && y<n && board[x][y]=='O'){
                    q.push(make_pair(x, y));
                    board[x][y] = 'B';
                }
            }
            
        } // end of While
        
    }
};

