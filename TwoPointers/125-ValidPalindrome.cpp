/**************************************************************************
 * File Name : 125-ValidPalindrome.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-12-2016
 *
 * Last Modified : Mon Dec 26 18:22:46 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isPalindrome(string s) {
        
        //s = "race a car";
        /*
        s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalnum(c); } ), s.end());
        
        for(int i=0,j=s.size()-1; i<j; i++,j--){
            
            if(tolower(s[i])!=tolower(s[j])) return false;
        }
        */
        
        for(int i=0, j=s.size()-1; i<j ;i++, j--){
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;
            if(tolower(s[i])!=tolower(s[j])) return false;
        }
        
        return true;
    }
};
