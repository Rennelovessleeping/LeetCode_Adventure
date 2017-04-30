/**************************************************************************
 * File Name : 306-AdditiveNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 22:40:09 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isAdditiveNumber(string num) {
        
        for(int i=1; i<= (int)num.size()/2; i++) {
            for(int j=1; j <= ((int)num.size()-i)/2; j++){
                if(dfs(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(string num1, string num2, string num) {
        if((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) return false;
        string sum = add(num1, num2);
        if(sum == num) return true;
        
        if(num.size() <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0) return false;
        else return dfs(num2, sum, num.substr(sum.size()));
        
    }
    
    string add(string num1, string num2) { // write the add function to avoid overflow caused by using to_string(stoi());
        string res;
        int i = num1.size()-1, j = num2.size()-1, carry = 0;
        
        while(i>=0 || j>=0 || carry) {
            carry += (i>=0 ? num1[i--]-'0' : 0) + (j>=0 ? num2[j--]-'0' : 0);
            res = to_string(carry%10) + res;
            carry /= 10;
        }
        return res;
    }
};
