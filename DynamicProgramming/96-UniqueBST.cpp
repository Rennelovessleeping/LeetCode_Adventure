/**************************************************************************
 * File Name : 96-UniqueBST.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-01-2017
 *
 * Last Modified : Thu Jan 12 16:19:28 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// t[n] = t[n-1]*t[0] + t[n-2]*t[1] + ... + t[0]*t[n-1]
class Solution {
public:
    int numTrees(int n) {
        
        int t[n+1];
        t[0] = t[1] = 1;
        
        for(int i=2;i<=n;i++){
            t[i] = 0;
            for(int j=0;j<i;j++){
                t[i] += t[j] * t[i-1-j];
            }
        }
        
        return t[n];
        
    }
};
