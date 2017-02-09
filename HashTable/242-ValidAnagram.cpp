/**************************************************************************
 * File Name : 242-ValidAnagram.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-02-2017
 *
 * Last Modified : Wed Feb  8 20:02:28 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.size() != s.size()) return false;
        int map[256] ={0};
        int count = t.size();
        
        for(int i = 0;i<s.size();i++ ) map[s[i]]++; 
        for(int i = 0;i<t.size();i++ ) count -= (map[t[i]]-- > 0);
        
        return count == 0;
    }
};
