/**************************************************************************
 * File Name : 668-KthSmallestNumberInMultiplicationTable.cpp
 *
 * Purpose :
 *
 * Creation Date : 03-09-2017
 *
 * Last Modified : Sun Sep  3 21:07:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n;    
        
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(count(mid, m, n) < k) lo = mid + 1;
            else hi = mid;
        }
        
        return lo;
    }
    
    int count(int val, int m, int n) {
        int res = 0;
        for(int i=1; i<=m; i++) res += min(val/i, n);
        return res;
    }
};
