/**************************************************************************
 * File Name : 159-LongestSubstringWithAtMostTwoDistinctChars.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-02-2017
 *
 * Last Modified : Wed Feb  8 22:36:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Still use the idea of keep rolling a window for comparison
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        vector<int> map(256,0);
        
        int left = 0, right = 0, maxLen = 0, counter = 0; // Use counter to track distinct chars;
        while(right < s.size()){
            if(map[s[right++]]++ == 0) counter++;
            while(counter > 2){
                if(map[s[left++]]-- == 1) counter--;
            }
            maxLen = max(maxLen, right-left);
        }
        return maxLen;
    }
};
