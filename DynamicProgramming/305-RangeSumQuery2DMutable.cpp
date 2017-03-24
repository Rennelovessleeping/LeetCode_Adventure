/**************************************************************************
 * File Name : 305-RangeSumQuery2DMutable.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-03-2017
 *
 * Last Modified : Fri Mar 24 15:41:20 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// solution based on BIT, it's just about how BIT stores element and each axis is independent
class NumMatrix {
public:
    int m, n;
    vector<vector<int>> matrix;
    vector<vector<int>> BIT;
    NumMatrix(vector<vector<int>> matrix) {
        this->matrix =  matrix;
        m = matrix.size();
        n = m ? matrix[0].size() : 0;
        
        BIT = vector<vector<int>> (m+1, vector<int>(n+1, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) init(matrix[i][j], i, j);
        }
    }
    
    void init(int val, int row, int col){

        for(int i=row+1; i <= m; i += (i & -i)){
            for(int j=col+1; j <= n; j += (j & -j)){
                BIT[i][j] += val;
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - matrix[row][col];
        matrix[row][col] = val;
        init(diff, row, col);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2+1, col2+1) + getSum(row1, col1) - getSum(row2+1, col1) - getSum(row1, col2+1);
    }
    
    int getSum(int row, int col){
        int sum = 0;
        for(int i= row; i > 0; i -= (i & -i)){
            for(int j=col; j > 0; j -= (j & -j)){
                sum += BIT[i][j];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
