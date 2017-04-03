/**************************************************************************
 * File Name : 87-ScrambleString.cpp
 *
 * Purpose :
 *
 * Creation Date : 03-04-2017
 *
 * Last Modified : Mon Apr  3 15:43:57 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Recursive solution
class Solution {
public:
    bool isScramble(string s1, string s2) {

        if(s1 == s2) return true;
        int cnt[26] = {0};
        
        int n = s1.size();
        for(int i=0; i<n; i++) {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++) {
            if(cnt[i]) return false;
        }
        
        for(int i=1; i<=n-1; i++) {
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            if(isScramble(s1.substr(0,i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0,n-i))) return true;
        }
        
        return false;
    }
};

// Memorization with DP:


