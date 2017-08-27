/**************************************************************************
 * File Name : 660-Remove9.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-08-2017
 *
 * Last Modified : Sun Aug 27 17:33:26 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Simply look for the 9-base representation of n
class Solution {
public:
    int newInteger(int n) {
        int res = 0, base = 1;
        while(n) {
            res += n%9*base;
            n /= 9;
            base *= 10;
        }
        return res;
    }
};
