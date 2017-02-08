/**************************************************************************
 * File Name : 409-LongestPalindrome.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-02-2017
 *
 * Last Modified : Tue Feb  7 23:57:05 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> map((int)pow(2, sizeof(char)*8), 0);
        int len = 0;
        for(int i=0;i<s.size();i++) map[s[i]]++;
        
        for(auto x:map){
            len += (x&1) == 0 ? x : x-1;
        }
        
        return len < s.size() ? len+1:len;
    }
};

// Concise solution
class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        for(char c='A';c<='z';c++) {
            len += count(s.begin(), s.end(), c) & 1;
        }
        return s.size() - len + (len >0);
    }
};
