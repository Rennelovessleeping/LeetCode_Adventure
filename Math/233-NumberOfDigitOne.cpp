/**************************************************************************
 * File Name : 233-NumberOfDigitOne.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-04-2017
 *
 * Last Modified : Sun Apr 23 13:27:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// To count how many ones occur in 10^k, we need to consider how many 10^(k+1) is included in n. 
// e.g. 20, 30, ... are equivalent to 100
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        
        for(long k=1; k<=n; k*=10) {
            int r = n/k, m = n%k;
            res += (r+8)/10*k + (r%10 == 1 ? m+1 : 0);
        }
        
        return res;
    }
};
