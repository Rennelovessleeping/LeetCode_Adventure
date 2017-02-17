/**************************************************************************
 * File Name : 186-ReverseWordsInStringII.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-02-2017
 *
 * Last Modified : Thu Feb 16 23:21:24 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Reverse two times
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        
        for(int i=0, j=0; i<s.size(); i=j+1){
            for(j=i; j < s.size() && !isblank(s[j]); j++);
            reverse(s.begin()+i, s.begin()+j);
        }
        
    }
};
