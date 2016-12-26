/**************************************************************************
 * File Name : 8-StringToInteger.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-12-2016
 *
 * Last Modified : Sun Dec 25 20:34:21 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int myAtoi(string str) {

        int i=0,j;
        int sign;
        long num = 0;
        while(str[i]==' ') i++;
        
        if(str[i]=='-') {sign = -1; i++;}
        else if(str[i]=='+') {sign = 1;i++;}
        else sign = 1;
        
        for(j=0;str[i+j]>='0' &&str[i+j]<='9';j++){
            num *= 10;
            num += str[i+j]-'0';
            if(num*sign < INT_MIN) return INT_MIN;
            if(num*sign > INT_MAX) return INT_MAX;
        }
        
        return num*sign;
        
    }
};
