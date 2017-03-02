/**************************************************************************
 * File Name : 50-nthPowOfX.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-01-2017
 *
 * Last Modified : Tue Feb 28 21:40:32 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Binary Search
class Solution {
public:
    double myPow(double x, long int n) {
        if(n==0) return 1.0;
        if(n<0) { n = -n; x = 1/x;}
        return n%2==0 ? myPow(x*x,n/2) : x*myPow(x*x, n/2);
    }
};

// Bit manipulation
class Solution {
public:
    double myPow(double x, long int n) { 
        if(n==0) return 1.0;
        if(n<0) { n = -n; x = 1/x;}
        
        double ans = 1;
        while(n>0){
            if(n&1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};
