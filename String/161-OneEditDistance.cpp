/**************************************************************************
 * File Name : 161-OneEditDistance.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-02-2017
 *
 * Last Modified : Sun Feb 12 17:15:47 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return isOneEditDistance(t, s);
        if(n-m > 1) return false;
        
        bool mis = false;
        for(int i=0; i<m;i++){
            if(s[i]!=t[i]) {
                if(m==n) s[i] = t[i];
                else s.insert(i, 1, t[i]);
                mis = true;
                break;
            }
        }
        
        return (mis && s==t) || (n-m == 1) && !mis;
    }
};

