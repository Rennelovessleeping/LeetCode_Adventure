/**************************************************************************
 * File Name : 459-RepeatedSubstringPattern.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-01-2017
 *
 * Last Modified : Sun Jan  1 22:39:49 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Naive patter searching.
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        
        if(str.size()<=1) return false;
        string pattern(1, str[0]);
        int len = str.size();
        
        for(int i=len/2;i>=1;i--){ // i is the length of substr
            if(len%i==0){
                int j=i;
                for(;j<len;j+=i){
                    if( !(str.substr(0,i)==str.substr(j,i)) ) break;
                }
                if(j==len) return true;
            }
        }
        
        return false;
        
    }
};

// KMP

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        
        // Using KMP to search the pattern "str" within str.
        
        int i=1, j=0, len=str.size();
        int t[len+1]={0};
        
        while(i<len){
            if(str[i] == str[j]) t[++i] = ++j;
            else if(j==0) i++;
            else j = t[j];
        }
        
        return t[len] && (t[len]%(len-t[len])==0);
    }
};
