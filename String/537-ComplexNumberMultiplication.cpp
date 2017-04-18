/**************************************************************************
 * File Name : 537-ComplexNumberMultiplication.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-04-2017
 *
 * Last Modified : Mon Apr 17 18:37:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        stringstream aa(a), bb(b);
        
        int real_a, imag_a, real_b, imag_b;
        char tmp; // '+' and 'i'
        aa >> real_a >> tmp >> imag_a;
        bb >> real_b >> tmp >> imag_b;
        
        return to_string(real_a*real_b - imag_a*imag_b) + '+' + to_string(real_a*imag_b + imag_a*real_b) + "i";
    }
};
