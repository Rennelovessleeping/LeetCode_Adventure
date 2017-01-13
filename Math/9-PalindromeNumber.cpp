/**************************************************************************
 * File Name : 9-PalindromeNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-01-2017
 *
 * Last Modified : Mon Jan  2 13:12:05 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0 || (x!=0 && x%10==0) ) return false;
        int reverseNum=0;
        
        while(x > reverseNum){
            reverseNum = reverseNum*10 + x%10;
            x /= 10;
        }
        //cout << x << ", " << reverseNum/10 << endl;
        return reverseNum==x || x==reverseNum/10;
    }
};
