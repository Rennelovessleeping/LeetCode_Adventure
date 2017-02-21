/**************************************************************************
 * File Name : 151-ReverseWordInString.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-02-2017
 *
 * Last Modified : Sun Feb 19 13:31:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// two pointer + double revese
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        
        int start = 0; // using start to take account for extra ' ';
        
        for(int i=0; i<s.size() ;i++){
            if(!isblank(s[i])){ // encounter a word
                if(start != 0) s[start++]=' '; // put delimiter in the right place and then place it on end;
                int j=i;
                while(j<s.size() && !isblank(s[j])) s[start++] = s[j++]; 
                reverse(s.begin() + start-(j-i), s.begin() + start);
                i = j;
            }
        }
        s.erase(s.begin()+start, s.end());
    }
};
