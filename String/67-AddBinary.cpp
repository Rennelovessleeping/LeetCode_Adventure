/**************************************************************************
 * File Name : 67-AddBinary.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-01-2017
 *
 * Last Modified : Thu Jan 12 15:34:22 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string addBinary(string a, string b) {
        
        string result;
        int carry = 0;
        int digit;
        string::reverse_iterator rit_a, rit_b;
        for(rit_a = a.rbegin(), rit_b = b.rbegin(); rit_a!= a.rend() && rit_b!=b.rend(); rit_a++, rit_b++){
            digit = carry + (*rit_a - '0') + (*rit_b-'0');
            result.insert(result.begin(), (digit%2 +'0'));
            carry = digit/2;
        }
        
        while(rit_a!=a.rend()){
            digit = carry + (*rit_a - '0');
            result.insert(result.begin(), (digit%2 +'0'));
            carry = digit/2;
            rit_a++;
        }
        
        while(rit_b!=b.rend()){
            digit = carry + (*rit_b - '0');
            result.insert(result.begin(), (digit%2 +'0'));
            carry = digit/2;
            rit_b++;
        }
        
        if(carry) result.insert(result.begin(),'1');
        
        return result;
    }
};


// Refine
class Solution {
public:
    string addBinary(string a, string b) {
        
        string result;
        int carry = 0, i = a.size()-1, j = b.size()-1;
        int digit;
        
        while(i>=0 || j>=0 || carry){
            carry += i >= 0 ? a[i--]-'0' : 0;
            carry += j >= 0 ? b[j--]-'0' : 0;
            result = char(carry%2 + '0') + result;
            carry /= 2;
        }
        return result;
    }
};
