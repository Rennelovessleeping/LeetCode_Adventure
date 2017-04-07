/**************************************************************************
 * File Name : 65-ValidNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-04-2017
 *
 * Last Modified : Thu Apr  6 18:52:03 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isNumber(string s) {
        auto start = s.find_first_not_of(' ');
        if(start == string::npos) return false;
        auto end = s.find_last_not_of(' ');
        // cout << start << ", " << end << endl;
        s = s.substr(start, end-start+1);
        
        bool decimalSeen = false;
        bool eSeen = false;
        bool numberSeen = false;
        bool numberAfterE = true;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '+' || s[i] == '-') {
                if(i!=0 && s[i-1] != 'e' ) return false;
            }
            else if(isdigit(s[i])) {
                numberSeen = true;
                numberAfterE = true;
            }
            else if(s[i] == '.') {
                if(decimalSeen || eSeen) return false;
                decimalSeen = true;
            }
            else if(s[i] == 'e') {
                if(eSeen || !numberSeen) return false;
                numberAfterE = false;
                eSeen = true;
            }
            else return false;
        }
        
        return numberSeen && numberAfterE;
    }
    
};
