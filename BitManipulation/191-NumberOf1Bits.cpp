/**************************************************************************
 * File Name : 191-NumberOf1Bits.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-01-2017
 *
 * Last Modified : Mon Jan 16 14:38:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        while(n > 0){
            if(n&1) count++;
            n >>= 1;
        }
        return count;
    }
};
