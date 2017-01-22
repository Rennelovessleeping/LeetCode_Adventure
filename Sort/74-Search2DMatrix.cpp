/**************************************************************************
 * File Name : 74-Search2DMatrix.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-01-2017
 *
 * Last Modified : Sat Jan 21 18:30:45 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()==0) return false;
        int m = matrix.size(), n = matrix[0].size(), idx;
        int left = 0, right = m*n-1, mid;
        
        while(left <= right){
            mid = left + (right - left)/2;
            int i= mid/n, j=mid%n;
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) right = mid - 1;
            else left = mid + 1;
        }
        
        return false;
        
    }
};
