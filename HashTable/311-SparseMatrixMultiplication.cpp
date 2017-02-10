/**************************************************************************
 * File Name : 311-SparseMatrixMultiplication.cpp
 *
 * Purpose :
 *
 * Creation Date : 10-02-2017
 *
 * Last Modified : Fri Feb 10 16:36:15 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// One can store the huge sparse matrix as a hastable
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int rowA = A.size(), colA = A[0].size(), colB = B[0].size();
        vector<vector<int>> ans(rowA, (vector<int>(colB, 0)));
        
        for(int i=0;i<rowA;i++){
            for(int k=0;k<colA;k++){
                if(A[i][k] !=0 ){
                    for(int j=0;j<colB;j++){
                        if(B[k][j] != 0) ans[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        
        return ans;
    }
};

