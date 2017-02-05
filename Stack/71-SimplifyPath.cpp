/**************************************************************************
 * File Name : 71-SimplifyPath.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-02-2017
 *
 * Last Modified : Sun Feb  5 13:41:04 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string simplifyPath(string path) {
        
        string simpPath;
        stack<string> stk;
        
        istringstream ss(path);
        string cur;

        while(getline(ss, cur , '/')){
            if(cur == "." || cur == "") continue;
            else if(cur == "..") {
                if(!stk.empty()) stk.pop();
            }
            else stk.push(cur);
        }
        
        while(!stk.empty()){
            simpPath = "/" + stk.top() + simpPath;
            stk.pop();
        }
        
        return simpPath.empty() ? "/" : simpPath;
        
    }
};
