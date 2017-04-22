/**************************************************************************
 * File Name : 172-FactorialTrailingZeros.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-04-2017
 *
 * Last Modified : Sat Apr 22 18:03:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// one always get enough 2's from even factors to pair with 5, 25, 5^3...
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(long i=5; n/i>0 ; i*=5){
            res += n/i;
        }
        
        return res;
    }
};
