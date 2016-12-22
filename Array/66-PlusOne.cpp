/**************************************************************************
 * File Name : 66-PlusOne.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-12-2016
 *
 * Last Modified : Thu Dec 22 17:38:38 2016
 *
 * Created By :  
**************************************************************************/
// Naively manipulating digits
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int len = digits.size();
        int increment=0;
        digits[len-1]+=1;
        bool promotion; 
        
        for(int i=len-1;i>=0;i--){
            digits[i] += increment;
            increment = (digits[i] == 10) ? 1 : 0;
            digits[i] %= 10;
            
        }
        if (increment) digits.insert(digits.begin(),1);
        
        return digits;
    }
};

// Refine: Remember the first +1 is already a carry!
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int len = digits.size();
        bool promotion = true; 
        
        for(int i=len-1;i>=0 && promotion;i--){
            promotion = (++digits[i] %= 10) == 0;
            
        }
        if (promotion) digits.insert(digits.begin(),1);
        
        return digits;
    }
};
