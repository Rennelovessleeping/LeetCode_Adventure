/**************************************************************************
 * File Name : 446-ArithmeticSubsequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-03-2017
 *
 * Last Modified : Sun Mar 12 17:08:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// when use the first pair as diff, update dp table from back;
// when use the last pair as diff, update dp table from beginning;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0, n = A.size();
        if(n < 3) return res;
        
        vector<unordered_map<int, int>> dp(n); // {diff: count of arithmetic sequence with diff}
        for(int i=0; i < n; i++){
            for(int j=0; j<i; j++){
                if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;
                int diff = A[i] - A[j];
                dp[i][diff]++;
                if(dp[j].find(diff) != dp[j].end()){
                    dp[i][diff] += dp[j][diff];
                    res += dp[j][diff];
                }
            }
        }
        
        return res;
	} 
};
