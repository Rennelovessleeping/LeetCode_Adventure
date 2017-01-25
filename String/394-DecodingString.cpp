/**************************************************************************
 * File Name : 394-DecodingString.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-01-2017
 *
 * Last Modified : Tue Jan 24 23:10:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
ass Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }
    
private:
    string helper(string s, int& i){
        string res;
        int len = s.size();
        
        while(i<len && s[i] != ']'){
            if(!isdigit(s[i])) res += s[i++];
            else{
                int num = 0;
                while(i<len && isdigit(s[i])) num = num*10 + s[i++] - '0';
                // substr + numbers / numbers alone ahead of '[';
                i++; // skip '['
                string t = helper(s, i);
                i++; // skip ']'
                
                while(num--) res+=t;
            }
            
        }
        
        return res;
    }
    
};
