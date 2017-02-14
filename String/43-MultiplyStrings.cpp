/**************************************************************************
 * File Name : 43-MultiplyStrings.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-02-2017
 *
 * Last Modified : Mon Feb 13 20:16:01 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.length() + num2.length(), '0');
        
        for(int i=num1.length()-1; i>=0; i--){
            int carry = 0;
            for(int j=num2.length()-1; j>=0; j--){
                int tmp = res[i+j+1] - '0' + (num1[i]-'0')*(num2[j]-'0') + carry ;
                res[i+j+1] = tmp%10 + '0';
                carry = tmp /10;
            }
            res[i] += carry;
        }
        
        size_t startpos = res.find_first_not_of('0');
        return startpos == string::npos ? "0" : res.substr(startpos);
    }
};
