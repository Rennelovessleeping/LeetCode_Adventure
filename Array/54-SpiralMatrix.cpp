/**************************************************************************
 * File Name : 54-SpiralMatrix.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-03-2017
 *
 * Last Modified : Thu Mar  9 15:37:03 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        vector<int> res(m*n);
        int l = 0 , r = n-1, u = 0, d = m-1, k = 0;
        
        while(true){
            // going right
            for(int i=l; i<=r; i++) res[k++] = matrix[u][i];
            
            // going down
            if(++u > d) break;
            for(int i=u; i<=d; i++) res[k++] = matrix[i][r];
            
            //going left
            if(--r < l) break;
            for(int i=r; i>=l; i--) res[k++] = matrix[d][i];
            
            //going up
            if(--d < u) break;
            for(int i=d; i>=u; i--) res[k++] = matrix[i][l];
            
            if(++l > r) break;
        }
        
        return res;
    }
};
