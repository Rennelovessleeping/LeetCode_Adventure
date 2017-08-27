/**************************************************************************
 * File Name : 625-MinimumFactorization.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-08-2017
 *
 * Last Modified : Sun Aug 27 17:32:16 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 2) return a;
        string res(10 ,'0');
        for(int d=9, i=9; d>=2 && i; d--) {
            while(a % d==0 && i) {
                res[i--] = d + '0';
                a /= d;
            }
        }
        
        return a > 1 || stol(res) > INT_MAX ? 0 : stoi(res);
    }
};
