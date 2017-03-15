/**************************************************************************
 * File Name : 214-ShortestPalindrome.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-03-2017
 *
 * Last Modified : Tue Mar 14 18:45:38 2017
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

