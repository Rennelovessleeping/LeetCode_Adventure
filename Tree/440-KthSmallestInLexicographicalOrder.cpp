/**************************************************************************
 * File Name : 440-KthSmallestInLexicographicalOrder.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-04-2017
 *
 * Last Modified : Sat Apr 15 17:44:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Tenary Tree
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k = k-1;
        
        while(k > 0) {
            int steps = calc_level_steps(n, cur, cur+1);
            if(steps <=k ) {
                k -= steps;
                cur += 1;
            }
            else {
                k -= 1;
                cur *= 10;
            }
        }
        
        return cur;
    }
    
    int calc_level_steps(long n, long n1, long n2) {
        int res = 0;
        while(n1 <= n) {
            res += min(n2, n+1) - n1;
            n1 *= 10; // Move to next Level
            n2 *= 10;
        }
        return res;
    }    
};
