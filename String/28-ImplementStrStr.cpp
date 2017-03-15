/**************************************************************************
 * File Name : 28-ImplementStrStr.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-03-2017
 *
 * Last Modified : Tue Mar 14 22:53:24 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// KMP solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        vector<int> lps = build_lps(needle);
        
        for(int i=0, j=0; i<haystack.size(); ){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            if(j==needle.size()) return i-j;
            if(i<haystack.size() && haystack[i] != needle[j]){
                if(j) j = lps[j-1];
                else i++;
            }
        }
        return -1;
        
    }

private:
    vector<int> build_lps(string s){
        vector<int> lps(s.length(), 0);
        for(int i=1, j=0; i<lps.size();){
            if(s[i] == s[j]){
                lps[i] = j + 1;
                j++;
                i++;
            }
            else{
                while(j && s[i] != s[j]) j = lps[j-1];
                if(s[i] == s[j]) j++;
                lps[i++] = j;
            } 
        }
        
        return lps;
    }
};
