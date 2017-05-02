/**************************************************************************
 * File Name : 567-PermutationInString.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-05-2017
 *
 * Last Modified : Mon May  1 19:46:38 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size() > s2.size()) return false;
        vector<int> cnt(26,0);
        
        for(int i=0; i<s1.size(); i++) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        
        
        
        if(isValid(cnt)) return true;
        
        for(int len = s1.size(), i=len; i<s2.size(); i++) {
            cnt[s2[i] - 'a']--;
            cnt[s2[i-len] - 'a']++;
            if(isValid(cnt)) return true;
        }
        
        return false;
    }
    
    bool isValid(const vector<int>& cnt) {
        for(int i=0; i<26; i++){
            if(cnt[i]) return false;
        }
        return true;
    }
};
