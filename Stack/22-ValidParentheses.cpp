/**************************************************************************
 * File Name : 22-ValidParentheses.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-01-2017
 *
 * Last Modified : Sun Jan 15 15:22:57 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isValid(string s) {
        
        if(s.size()<2) return false;
        
        stack<char> res;
        res.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!res.empty() && (s[i]-res.top()==1 || s[i]-res.top()==2) ) res.pop();
            else res.push(s[i]);
        }
        
        return res.empty();
        
    }
};
