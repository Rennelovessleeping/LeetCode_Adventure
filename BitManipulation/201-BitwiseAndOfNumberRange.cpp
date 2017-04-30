/**************************************************************************
 * File Name : 201-BitwiseAndOfNumberRange.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sun Apr 30 11:37:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return n > m ? (rangeBitwiseAnd(m>>1, n>>1) << 1) : m;
    }
};
