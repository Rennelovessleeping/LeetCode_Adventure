/**************************************************************************
 * File Name : 76-MinimumWindowSubstring.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-02-2017
 *
 * Last Modified : Wed Feb 22 13:48:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, head = 0;
        int minLength = INT_MAX;
        int counter = t.size(); 
        
        vector<int> map((int) sizeof(char)*8, 0);

        for(int i=0;i<t.size();i++) map[t[i]]++;
        
        while(right < s.size()){
            if(map[s[right++]]-- > 0) counter--;
            while(counter == 0){
                if(right-left<minLength) minLength = right-(head=left); 
                if(map[s[left++]]++==0) counter++;  // keep moving left until reach a char in strin t
            }
 
        }
        return minLength == INT_MAX ? "" : s.substr(head, minLength);
    }
    
};
