/**************************************************************************
 * File Name : 73-SetMatrixZeroes.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-02-2017
 *
 * Last Modified : Mon Feb  6 20:06:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int m = matrix.size();
        if(matrix[0].size() == 0) return;
        int n = matrix[0].size();
        
        vector<vector<bool>> flipped(m, vector<bool>(n,false)); 
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(matrix[i][j] == 0 && !flipped[i][j]){
                    for(int k=0;k<n;k++) {
                        if(matrix[i][k] == 0) continue;
                        matrix[i][k] = 0;
                        flipped[i][k] = true;
                    }
                    for(int k=0;k<m;k++){
                        if(matrix[k][j] == 0) continue;
                        matrix[k][j] = 0;
                        flipped[k][j] = true;
                    }
                    flipped[i][j] = true;
                }
                
            }
        }
        return; 
    }
    
};


