/**************************************************************************
 * File Name : 227-BasicCaculatorII.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-04-2017
 *
 * Last Modified : Wed Apr 12 19:35:35 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int calculate(string s) {
        istringstream ss('+' + s + '+'); // last '+' to add the last term
        long int res = 0, num, term = 0;
        char op;
        
        while(ss >> op) {
            if(op == '+' || op == '-') {
                res += term;
                ss >> term;
                term *= op == '+' ? 1 : -1;
            }
            else{
                ss >> num;
                if(op == '*') term *= num;
                else term /= num;
            }
        }
        
        return res;
    }
};
