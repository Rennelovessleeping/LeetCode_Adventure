/**************************************************************************
 * File Name : 190-ReverseBits.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-01-2017
 *
 * Last Modified : Mon Jan 16 15:09:00 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans = 0;
        
        for(int i=1;i<32;i++){
             ans += n&1;
             ans <<= 1;
             n >>= 1;
        }
        ans += n&1;
        return ans;
    }
};


// Divide and Conquer
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        
        return n;
    }
};
