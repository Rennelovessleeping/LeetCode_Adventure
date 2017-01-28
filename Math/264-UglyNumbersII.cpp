/**************************************************************************
 * File Name : 264-UglyNumbersII.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-01-2017
 *
 * Last Modified : Sat Jan 28 13:35:15 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution
class Solution {
public:
    int nthUglyNumber(int n) {
        // DP solutin for generating ugly numbers in ascending order;
        vector<int> uglyNums(n);
        uglyNums[0] = 1;
        int pos2 = 0, pos3 = 0, pos5 = 0;
        for(int i=1;i<n;i++){
            uglyNums[i] = min(2*uglyNums[pos2], min(3*uglyNums[pos3], 5*uglyNums[pos5]));
            if(uglyNums[i] == 2*uglyNums[pos2]) pos2++;
            if(uglyNums[i] == 3*uglyNums[pos3]) pos3++;
            if(uglyNums[i] == 5*uglyNums[pos5]) pos5++;
        }
        
        return uglyNums[n-1];
    }
};
