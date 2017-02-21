/**************************************************************************
 * File Name : 516-LongestPalindromicSubsequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-02-2017
 *
 * Last Modified : Tue Feb 21 16:28:19 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution: use dp[n][n] table to record the longest palindromic subarray length with i and j inclusive
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        vector<vector<int>> dp(len,vector<int>(len));
        
        for(int i=1; i<=len; ++i){
            for(int left = 0; left+i <= len; ++left){
                int right = i - 1 + left; // right - left + 1 =i;
                if(left == right) dp[left][right] = 1;
                else if(left +1 == right) dp[left][right] = s[left] == s[right] ? 2 : 1;
                else{
                    int incr = s[left] == s[right] ? 2: 0;
                    dp[left][right] = max(max(dp[left+1][right], dp[left][right-1]), dp[left+1][right-1] + incr);
                    // left+1 & right-1 is the direction to shrink the size of current substring
                }
                
            }
        }
        
        return dp[0][len-1];
    }
};

