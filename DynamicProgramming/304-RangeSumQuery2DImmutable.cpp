/**************************************************************************
 * File Name : 304-RangeSumQuery2DImmutable.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-02-2017
 *
 * Last Modified : Tue Feb 21 21:40:20 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Dynamic programming solution
class NumMatrix {
public:
    vector<vector<int>> cumsum;
    int m,n;
    NumMatrix(vector<vector<int>> matrix) {
        m = matrix.size();
        n = m>0 ? matrix[0].size() : 0;
        
        cumsum = vector<vector<int>> (m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                cumsum[i][j] = matrix[i-1][j-1] + cumsum[i-1][j] + cumsum[i][j-1] - cumsum[i-1][j-1];    
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cumsum[row2+1][col2+1] - cumsum[row2+1][col1] - cumsum[row1][col2+1] + cumsum[row1][col1];
    }
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

