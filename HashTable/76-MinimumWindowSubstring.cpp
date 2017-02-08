/**************************************************************************
 * File Name : 76-MinimumWindowSubstring.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-02-2017
 *
 * Last Modified : Tue Feb  7 22:53:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, head = 0;
        int minLength = INT_MAX;
        int counter = t.size(); 
        
        vector<int> map((int)pow(2, sizeof(char)*8), 0);

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
