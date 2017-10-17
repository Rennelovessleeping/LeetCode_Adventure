/**************************************************************************
 * File Name : 214-ShortestPalindrome.cpp
 *
 * Purpose :
 * * Creation Date : 14-03-2017
 *
 * Last Modified : Sat Oct 14 17:43:30 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// We only need to find the longest palindromic substring startig from the beginning;
// use the lps table to find that
class Solution {
public:
    string shortestPalindrome(string s) {
        int len = build_lps(s + '#' + string (s.rbegin(), s.rend()));
        string pre = s.substr(len);
        reverse(pre.begin(), pre.end());
        return pre + s;
    }
    
private:
    int build_lps(string s){
        vector<int> lps(s.size(), 0);
        for(int i=1, j=0; i<s.size(); i++){
            if(s[i] == s[j]){
                lps[i] = lps[i-1] + 1;
                j++;
            }
            else{
                j = lps[i-1];
                while(j>0 && s[i] != s[j]) j = lps[j-1];
                if(s[i] == s[j]) j++;
                lps[i] = j;
            }
        }
        return lps.back();
    }
};

// recursive solution: the key idea is to find the longest palindromic prefix. --> we can use two pointer to judge
// the substring contain it.
class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0, len = s.size();
        for(int j=len-1; j>=0; j--) if(s[i]==s[j]) i++;
        if(i == len) return s;
        string suffix = s.substr(i);
        return string (suffix.rbegin(), suffix.rend()) + shortestPalindrome(s.substr(0, i)) + suffix;
    }
};
