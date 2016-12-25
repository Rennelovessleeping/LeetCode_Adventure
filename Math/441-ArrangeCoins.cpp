/**************************************************************************
 * File Name : 441-ArrangeCoins.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-12-2016
 *
 * Last Modified : Sun Dec 25 13:43:18 2016
 *
 * Created By :  
**************************************************************************/
#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {//Newtown's method
        
        if(n==0) return 0;
        double k=n; // initial guess
        double epsilon = pow(10,-6);
        double fk = f(k,n);
        while(fk>epsilon){
            k = - fk/fprime(k,n) + k;
            fk = f(k,n);
            //cout << fk << endl;
        }
        return floor(k);
        
    }
    double f(double k, int n){
        return 0.5*k*k + 0.5*k - n;
    }
    double fprime(double k, int n){
        return k + 0.5;
    }
    
};

int main(){
    
    Solution s;
    int n = 16;
    int k = s.arrangeCoins(n);
    cout << "The final result is " << k << endl;
    cout << s.f(k, n) + n << endl;
    cout << s.f(k+1, n) + n << endl;
    return 0;

}

