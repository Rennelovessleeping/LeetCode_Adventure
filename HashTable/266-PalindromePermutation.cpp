/**************************************************************************
 * File Name : 266-PalindromePermutation.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-02-2017
 *
 * Last Modified : Wed Feb  8 20:19:59 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int map[256] {0};
        int oddCount = 0;
        for(int i=0; i<s.size();i++) map[s[i]]++;
        for(int i=0;i<256;i++) oddCount += (map[i] &1);
        
        return  oddCount <= 1;
    }
};

