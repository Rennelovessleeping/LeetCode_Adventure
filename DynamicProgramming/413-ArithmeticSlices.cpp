/**************************************************************************
 * File Name : 413-ArithmeticSlices.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-03-2017
 *
 * Last Modified : Sun Mar 12 12:28:47 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res  = 0;
        int n = A.size();
        if(n < 3) return res;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int len = 3; len<=n; len++){
            for(int i=0; i+len <= n; i++){
                int j = i + len -1;
                if(len ==3) dp[i][j] = A[j] + A[j-2] == 2*A[j-1];
                else dp[i][j] = dp[i][j-1] && A[j] + A[j-2] == 2*A[j-1];
                res += dp[i][j];
            }
        }
        return res;
    }
};

// conciser solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        if(n < 3) return res;
        vector<int> dp(n, 0);
        
        for(int i=2; i<n; i++){
            if(2*A[i-1] == A[i] + A[i-2]) dp[i] = dp[i-1] + 1;
            res += dp[i];
        }
        return res;
    }
};
