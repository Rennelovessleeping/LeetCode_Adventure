/**************************************************************************
 * File Name : 395-LongestSubstringWithAtLeastKRepeatingCharacters.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-03-2017
 *
 * Last Modified : Wed Mar 15 23:10:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DC solution 
// Avoid repeated search
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty() || s.size() < k) return 0;
        if(k==0) return s.size();
        
        vector<int> mp(26,0);
        for(int i = 0; i < s.size(); i++){
            mp[s[i] - 'a']++;
        }
        
        int idx = 0;
        while(idx < s.size() && mp[s[idx]-'a'] >=k) idx++;
        if(idx == s.size()) return s.size();
        
        int maxLen = 0;
        for(int start = 0; start < s.size(); ){
            while(start < s.size() && mp[s[start]-'a'] < k ) start++;
            if(start == s.size()) break;
            int end = start;
            while(end < s.size() && mp[s[end]-'a'] >= k ) end++;
            maxLen = max(maxLen, longestSubstring(s.substr(start, end-start), k));
            // Need to check the length of substr
            start = end;
        }
    
        return maxLen;
    }
};
