/**************************************************************************
 * File Name : 388-LongestAbsoluteFilePath.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-04-2017
 *
 * Last Modified : Tue Apr 18 23:09:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Maintain a stack to record the len to current dir
class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> stk;
        stk.push(0); // dummy root level
        stringstream ss(input);
        int res = 0;
        string file;
        
        while(getline(ss, file, '\n')) {
            int level = file.find_last_of('\t') + 1; // how many '\t'
            while(level+1 < stk.size()) stk.pop(); // back to ancestor dir
            int len = stk.top() + file.length() - level + 1; // level--'\t', +1 -> add '/'
            stk.push(len);
            if(file.find('.') != string::npos) res = max(res, len-1);
        }
        
        return res;
    }
};
