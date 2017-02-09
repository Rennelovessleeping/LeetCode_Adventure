/**************************************************************************
 * File Name : 5-LongestPalindromicSubstring.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-02-2017
 *
 * Last Modified : Wed Feb  8 21:34:32 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Only better than brute force;
class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0, maxLength = 0;
        
        for(int i=0; i<s.size();){
            if(s.size()-i <= maxLength/2) break;
            
            int left=i, right =i;
            while(right < s.size()-1 && s[right] == s[right+1]) right++;
            
            i = right + 1; // next expanding center;
            
            while(left>0 && right<s.size()-1 && s[left-1] == s[right+1]) {left--; right++;}
            if( right-left+1 > maxLength) {
                start = left;
                maxLength = right-left+1;
            }
        }
        
        return s.substr(start, maxLength);
    }
    
};

// Brute force solution
class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> map(256,0);
        int start = 0, maxLength = 0;
        for(int i=0; i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if ((j-i+1)>maxLength && isPalindrome(s, i, j)){
                    start = i;
                    maxLength = j-i+1;
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
    
private:
    bool isPalindrome(string& s, int i, int j){
        if (j<=i) return true;
        return s[i]==s[j] && isPalindrome(s, i+1, j-1);
    }
};


