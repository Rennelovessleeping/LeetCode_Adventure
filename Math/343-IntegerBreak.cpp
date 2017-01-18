/**************************************************************************
 * File Name : 343-IntegerBreak.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-01-2017
 *
 * Last Modified : Wed Jan 18 16:38:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int integerBreak(int n) {
        
        if(n==2) return 1;
        if(n==3) return 2;
        
        int ans = 1;
        while(n>4){ // No need to break into 3's when n<=4;
            ans *= 3;
            n -= 3;
        }
        
        cout << n;
        return ans*=n;
    }

};

