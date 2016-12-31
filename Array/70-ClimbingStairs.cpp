/**************************************************************************
 * File Name : 70-ClimbingStairs.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-12-2016
 *
 * Last Modified : Sat Dec 31 16:06:02 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Raw DP
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0) return 0;
        int curr[n];
        curr[0] = 1;
        curr[1] = 2;
        
        
        for(int i=2;i<n;i++){
            // state equation
            curr[i] = curr[i-1] + curr[i-2];
        }
        
        return curr[n-1];
        
    }
};

// Space optimization
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int ans;
		// Note the difference on initialization
        int preOne = 2;
        int preTwo = 1;
        
        
        for(int i=2;i<n;i++){
            ans = preOne + preTwo;
            preTwo = preOne;
            preOne = ans;
        }
        
        return ans;
        
    }
};

