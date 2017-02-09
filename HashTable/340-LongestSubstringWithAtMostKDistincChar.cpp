/**************************************************************************
 * File Name : 340-LongestSubstringWithAtMostKDistincChar.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-02-2017
 *
 * Last Modified : Wed Feb  8 22:52:20 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Same idea of Q159
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        vector<int> map(256,0);
        
        int left = 0, right = 0, maxLen = 0, counter = 0;
        
        while(right<s.size()){
            if(map[s[right++]]++ == 0) counter++;
            while(counter > k){
                if(map[s[left++]]-- == 1) counter--;
            }
            maxLen = max(maxLen, right-left);
        }
        return maxLen;
    }
};
