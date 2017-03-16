/**************************************************************************
 * File Name : 32-LongestValidParentheses.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-03-2017
 *
 * Last Modified : Wed Mar 15 21:01:33 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') stk.push(i);
            else{
                if(!stk.empty() && s[stk.top()] == '(') stk.pop();
                else stk.push(i);
            }
        }
        if(stk.empty()) return s.size();
        
        int end = s.size(), start = 0, maxLen = INT_MIN;
        while(!stk.empty()){
            start = stk.top(); stk.pop();
            maxLen = max(maxLen, end-start-1);
            end = start;
        }
        maxLen = max(maxLen, start);
        return maxLen;
    }
};

// one can also use a dp array to record the valid blocks
