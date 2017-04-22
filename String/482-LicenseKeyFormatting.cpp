/**************************************************************************
 * File Name : 482-LicenseKeyFormatting.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-04-2017
 *
 * Last Modified : Fri Apr 21 22:46:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int len = S.length();
        for(int i=len-1; i>=0; i--) {
            if(S[i] == '-')  continue;
            if(res.size() % (K+1) == K) res = '-' + res;
            res = string(1,toupper(S[i])) + res;
        }
        
        return res;
    }
};
