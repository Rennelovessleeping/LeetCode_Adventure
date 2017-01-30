/**************************************************************************
 * File Name : 29-DivideTwoIntegers.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-01-2017
 *
 * Last Modified : Sun Jan 29 13:57:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(divisor == 0 || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
        
        int sign = (dividend>0 ^ divisor>0) ? -1 : 1;
        long d = labs(dividend);
        long s = labs(divisor);
        
        int res = 0;
        while(d >= s){
            long tmp = s, multiple=1;
            while(d >= (tmp<<1)){
                tmp <<= 1;
                multiple<<=1;
            }
            d -= tmp;
            res += multiple;
            
        }
        
        return sign >0 ? res : -res;
    }
};

