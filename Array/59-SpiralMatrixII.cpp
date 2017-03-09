/**************************************************************************
 * File Name : 59-SpiralMatrixII.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-03-2017
 *
 * Last Modified : Thu Mar  9 15:45:36 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n, vector<int>(n,0));
        int l = 0, r = n-1, u = 0, d = n-1, k = 1;
        while(true){
            //going right:
            for(int i=l; i<=r; i++) res[u][i] = k++;
            if(++u > d) break;
            
            //going down
            for(int i=u; i<=d; i++) res[i][r] = k++;
            if(--r < l) break;
            
            //going left
            for(int i=r; i>=l; i--) res[d][i] = k++;
            if(--d < u) break;
            
            //going up
            for(int i=d; i>=u; i--) res[i][l] = k++;
            if(++l > r) break;
        }
        
        return res;
    }
};
