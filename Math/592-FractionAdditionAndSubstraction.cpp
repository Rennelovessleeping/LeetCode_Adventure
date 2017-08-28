/**************************************************************************
 * File Name : 592-FractionAdditionAndSubstraction.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-08-2017
 *
 * Last Modified : Sun Aug 27 23:05:00 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string fractionAddition(string expression) {
        int d = 0, s = 1, a, b;
        char tmp;
        istringstream ss(expression);
        
        while(ss >> a >> tmp >> b) {
            d = d*b + a*s;
            s *= b;
            int g = abs(gcd(d, s));
            d /= g;
            s /= g;
        }
        
        return to_string(d) + '/' + to_string(s);
    }
    
    int gcd(int a, int b) {
        if(b==0) return a;
        else return gcd(b, a%b);
        
    }
};
