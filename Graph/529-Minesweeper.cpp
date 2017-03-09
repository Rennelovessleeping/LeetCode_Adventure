/**************************************************************************
 * File Name : 529-Minesweeper.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-03-2017
 *
 * Last Modified : Wed Mar  8 21:47:43 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BFS solution
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        int m = board.size(), n = m ? board[0].size() : 0;
        queue<pair<int, int>> q;
        q.push({click[0], click[1]});
        
        while(!q.empty()){
            int i = q.front().first, j = q.front().second;
            q.pop();
            int count = 0;
            for(int ii=-1; ii<=1; ii++){
                for(int jj=-1; jj<=1; jj++){
                    int x = i + ii, y = j + jj;
                    if(ii==0 && jj==0 || x<0 || x>=m || y<0 || y>=n) continue;
                    if(board[x][y] == 'M' || board[x][y] == 'X') count++;
                }
            }
            
            if(count != 0) board[i][j] = count + '0';
            else{
                board[i][j] = 'B'; // Need to mark the first empty space
                for(int ii=-1; ii<=1; ii++){
                    for(int jj=-1; jj<=1; jj++){
                        int x = i + ii, y = j + jj;
                        if(ii==0 && jj==0 || x<0 || x>=m || y<0 || y>=n) continue;
                        if(board[x][y] == 'E'){
                            q.push({x,y});
                            board[x][y] = 'B';
                        } 
                    }
                }
            }
            
        }
        
        return board;
    }
};
