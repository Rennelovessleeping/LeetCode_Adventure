/**************************************************************************
 * File Name : 378-KthSmallestElementInASortedMatrix.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-01-2017
 *
 * Last Modified : Thu Jan 26 13:50:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Binary search solution
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1];
        
        while(left < right){
            int counter = 0, mid = left + (right-left)/2;
            for(int i=0;i<m;i++){
                counter += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(counter < k) left = mid+1;
            else right = mid;
            
        }
        return left;
    }
};


