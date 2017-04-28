/**************************************************************************
 * File Name : 467-UniqueSubstringsInWrapAroundString.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-04-2017
 *
 * Last Modified : Thu Apr 27 22:41:46 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// "abcd" : "abcd", "bcd", "cd", "d"
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26, 0); // count[i]: max number of unique substr ends up with letter 'a' + i
        int maxLen = 0;
        for(int i=0; i<p.length(); i++) {
            if(i>0 && p[i] - p[i-1] == 1 || p[i-1] - p[i] == 25) maxLen++;
            else maxLen = 1;
            
            cnt[p[i]-'a'] = max(cnt[p[i]-'a'], maxLen);
        }
        
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
