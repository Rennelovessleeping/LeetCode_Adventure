/**************************************************************************
 * File Name : 137-SingleNumberII.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-04-2017
 *
 * Last Modified : Wed Apr 26 22:09:54 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Design a counter by bit;
        int x1 = 0, x2 = 0, mask = 0;
        for(int num:nums){
            x2 ^= num & x1;
            x1 ^= num;
            mask = ~(x1 & x2);
            x1 &= mask;
            x2 &= mask;
        }
        
        return x1; // p = 1(01), k = 3, m = upper(log k) = 4;
    }
};
