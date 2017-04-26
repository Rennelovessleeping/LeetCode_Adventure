/**************************************************************************
 * File Name : 247-StrobogrammaticNumberII.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-04-2017
 *
 * Last Modified : Tue Apr 25 20:25:54 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        int len = n;
        return findStrobogrammatic(n, len);
    }
    
    vector<string> findStrobogrammatic(int n, const int& len) {
        if(n==0) return vector<string> {""};
        if(n==1) return vector<string> {"0", "1", "8"};
        
        vector<string> tmp = findStrobogrammatic(n-2, len);
        vector<string> res;
        for(const auto& s:tmp) {
            if(n != len) res.push_back("0" + s + "0");
            res.push_back("1" + s + "1");
            res.push_back("8" + s + "8");
            res.push_back("6" + s + "9");
            res.push_back("9" + s + "6");
        }
        
        
        return res;
    }
};
