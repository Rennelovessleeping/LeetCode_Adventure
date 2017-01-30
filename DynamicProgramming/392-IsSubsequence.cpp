/**************************************************************************
 * File Name : 392-IsSubsequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-01-2017
 *
 * Last Modified : Sun Jan 29 19:19:50 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return true;
        if(t.find(s[0]) == string::npos) return false;
        int pos = t.find(s[0]) ;
        for(int i=1;i<s.size();i++){
            pos = t.find(s[i],pos+1);
            if(pos == string::npos) return false;
        }
        return true;
    }
};
