/**************************************************************************
 * File Name : 201-BitwiseAndOfNumberRange.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 11:13:18 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) { 
        return n > m ? rangeBitwiseAnd(m>>1, n>>1) : m; // if m != n, the last digit must be zero 
    }
};
