/**************************************************************************
 * File Name : 224-BasicCalculator.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-04-2017
 *
 * Last Modified : Wed Apr 12 20:47:37 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int res = 0, num = 0, sign = 1;
        
        for(int i=0; i<s.size(); i++) {
            if(isdigit(s[i]))  num = num*10 + s[i]-'0';
            else if(s[i] == '+') {
                res += sign*num;
                num = 0;
                sign = 1;
            }
            else if(s[i] == '-') {
                res += sign*num;
                num = 0;
                sign = -1;
            }
            else if(s[i] == '(') { // record the result before (
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                res += num*sign;
                num = 0;
                res *= stk.top(); stk.pop();
                res += stk.top(); stk.pop();
            }
        }
        
        if(num) res += sign*num;
        
        return res;
    }
};
