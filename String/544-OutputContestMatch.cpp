/**************************************************************************
 * File Name : 544-OutputContestMatch.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-04-2017
 *
 * Last Modified : Mon Apr 17 18:29:07 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> res(n);
        for(int i=0; i<n; i++) res[i] = to_string(i+1);
        
        while(n>1) {
            for(int i=0; i<n/2; i++) res[i] = '(' + res[i] + ',' + res[n-i-1] + ')';
            n /= 2;
        }
        
        return res[0];
    }
};
