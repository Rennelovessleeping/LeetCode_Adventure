/**************************************************************************
 * File Name : 51-NQueeens.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-03-2017
 *
 * Last Modified : Tue Mar  7 21:50:54 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        //vector<bool> takenCol(n, false);
        vector<vector<string>> res;
        vector<string> config(n,string(n, '.'));
        helper(res, config, 0, n);
        
        return res;
    }
private:
    void helper(vector<vector<string>>& res, vector<string>& config, int row, int n){
        if(row == n){
            res.push_back(config);
            return;
        } 
        for(int col=0; col<n; col++){
            if(!isValid(config, row, col, n)) continue;
            config[row][col] = 'Q';
            helper(res, config, row+1, n);
            config[row][col] = '.';
        }
    }
    
    bool isValid(vector<string>& config, int row, int col, int n){
        // check column;
        for(int i=0; i<row; i++){
            if(config[i][col] == 'Q') return false;
        }
        
        // check 45 diagonal;
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(config[i][j] == 'Q') return false;
        }
        
        // check 135 diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(config[i][j] == 'Q') return false; 
        }
        return true;
    }
};
