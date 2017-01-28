/**************************************************************************
 * File Name : 263-UglyNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-01-2017
 *
 * Last Modified : Sat Jan 28 13:05:10 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isUgly(int num) {
        if(num<1) return false;
        if(num==1) return true;
        
        for(int i=2;i<6;i++) // num%4 has already enumerated by num%2
            while(num%i==0) num /= i;
        
        return num==1;
    }
};
