/**************************************************************************
 * File Name : 294-FlipGameII.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-04-2017
 *
 * Last Modified : Sun Apr 16 16:01:57 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool canWin(string s) {
        return dfs(s);
    }
    
    bool dfs(string& s) {
        int len = s.size();
        for(int i=0; i<len-1; i++) {
            if(s[i] == '+' && s[i+1] == '+') {
                s[i] = s[i+1] = '-';
                bool tmp = !dfs(s); // second player can not win;
                s[i] = s[i+1] = '+';
                if(tmp) return true;
            }
        }
        
        return false;
    }
};
