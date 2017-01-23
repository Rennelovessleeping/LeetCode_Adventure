/**************************************************************************
 * File Name : 372-SuperPow.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-01-2017
 *
 * Last Modified : Mon Jan 23 14:21:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    const int base = 1337;
    int superPow(int a, vector<int>& b) { 
        // (a*b)%k = (a%k)*(b%k)%k 
        if(b.size()==0) return 1;
        int last_digit = b.back();
        b.pop_back();
        
		// Note the default pow return a float type
        return powmod(superPow(a, b), 10) * powmod(a,last_digit) % base; ;
    }
    
private:
    int powmod(int x, int n){
        int ans=1;
        x %= base;
        while(n>0){
            ans =  (ans*x) % base;
            n--;
        }
        return ans;
    }
    
};
