/**************************************************************************
 * File Name : 3-LongestSubstringWithoutRepeatingCharacters.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-02-2017
 *
 * Last Modified : Tue Feb  7 22:21:03 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map((int)pow(2, sizeof(char)*8), 0);
        int left = 0, right = 0;
        int counter = 0, maxLength = 0; // use counter to take account for repeating chars
        
        while(right < s.length()){
            if(map[s[right++]]++ >= 1) counter++;
            while(counter>0) if(map[s[left++]]-->1) counter--;
            maxLength = max(maxLength, right-left);
        }
        
        return maxLength;
    }
    
};
