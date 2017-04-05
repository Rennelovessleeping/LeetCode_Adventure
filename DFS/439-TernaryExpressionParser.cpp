/**************************************************************************
 * File Name : 439-TernaryExpressionParser.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-04-2017
 *
 * Last Modified : Wed Apr  5 17:24:50 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string parseTernary(string expression) {
        stack<char> stk;
        for(int i=expression.length()-1; i>=0; i--) { // group right-to-left
            if(!stk.empty() && stk.top() == '?') {
                stk.pop(); // pop '?';
                char first = stk.top(); stk.pop(); // pop first evaluated expr
                stk.pop(); // pop ':';
                char second = stk.top(); stk.pop();// pop second evaluated expr
                if(expression[i] == 'T') stk.push(first);
                else stk.push(second);
            }
            else stk.push(expression[i]);
        }
        
        return string(1, stk.top());
    }
    
};
