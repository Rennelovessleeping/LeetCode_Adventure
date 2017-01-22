/**************************************************************************
 * File Name : 240-SearchA2DMatrixII.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-01-2017
 *
 * Last Modified : Sat Jan 21 14:07:35 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Raw Binary Search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0 || matrix[0].size()==0) return false;
        
        int row = matrix.size(), col =  matrix[0].size();
        int leftCol, rightCol, midCol;
        int upRow, downRow, midRow;
        
        if(target < matrix[0][0] || target > matrix[row-1][col-1]) return false;
        
        // Binary Search by Row:
        for(int i=0;i<row;i++){
            leftCol = 0; rightCol = col-1; 
            while(leftCol <= rightCol){
                midCol = leftCol + (rightCol - leftCol)/2;
                
                if(matrix[i][midCol] == target) return true;
                else if(matrix[i][midCol] > target) rightCol = midCol -1;
                else leftCol = midCol + 1;
            }
        }
        
        // Binary Search by Column:
        for(int i=0;i<col;i++){
            upRow = 0; downRow = row-1; 
            while(upRow <= downRow){
                midRow = upRow + (downRow - upRow)/2;
                
                if(matrix[midRow][i] == target) return true;
                else if(matrix[midRow][i] > target) downRow = midRow - 1;
                else upRow = midRow + 1;
            }
            
        }
        
        return false;
    }
};

// O(m+n) Solution:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0 || matrix[0].size()==0) return false;
        
        int row = matrix.size(), col =  matrix[0].size();
        int i = 0, j = col - 1;
        
        while(i<row && j>=0){
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else j--;
        }
        
        return false;
    }
};


