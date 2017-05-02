/**************************************************************************
 * File Name : 424-LongestRepeatingCharacterReplacement.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-05-2017
 *
 * Last Modified : Mon May  1 17:56:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26] = {0};
        int n = s.size(), left = 0, right = 0;
        int maxCnt = 0, maxLen = 0;
        
        while(right < n) {
            maxCnt = max(maxCnt, ++mp[s[right++]-'A']); // put "right" pass the valid range by one
            while(right - left > maxCnt + k) --mp[s[left++] - 'A'];
            maxLen = max(maxLen, right-left);
        }
        
        return maxLen;
    }
};
