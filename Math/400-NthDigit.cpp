/**************************************************************************
 * File Name : 400-NthDigit.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-12-2016
 *
 * Last Modified : Sun Dec 25 15:04:26 2016
 *
 * Created By :  
**************************************************************************/
class Solution {
public:
    int findNthDigit(int n) {
        
        int d=1;
        long int sumDigits = 9*pow(10,d-1);
        while(sumDigits<n){
            d++;
            sumDigits += d*9*pow(10,d-1);
        }
        
        int relativeIdx = n-sumDigits + d*9*pow(10,d-1) - 1; 
        int num = relativeIdx/d + pow(10,d-1); // locate the number
        int nthDigit = d-1 - relativeIdx % d;
        
        for(int i=0;i<nthDigit;i++){
            num /= 10;
        }
        
        return num%10;
        
    }
};
