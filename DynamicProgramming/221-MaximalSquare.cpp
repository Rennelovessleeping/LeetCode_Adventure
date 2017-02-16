/**************************************************************************
 * File Name : 221-MaximalSquare.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-02-2017
 *
 * Last Modified : Wed Feb 15 22:20:29 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        if(n==0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int maxLen = 0;
        //Initialization
        for(int i=0; i<m ; ++i) {dp[i][0] = matrix[i][0] - '0'; maxLen = max(maxLen, dp[i][0]);}
        for(int i=0; i<n ; ++i) {dp[0][i] = matrix[0][i] - '0'; maxLen = max(maxLen, dp[0][i]);} 
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = matrix[i][j] - '0';
                int len = dp[i-1][j-1];
                if(len != 0 && matrix[i][j] != '0'){
                    int k = 1;
                    for(;k<=len && matrix[i][j-k]!='0' && matrix[i-k][j]!='0'; k++) {}
                    dp[i][j] = k;
                }
                maxLen = max(maxLen, dp[i][j]);
                
            }
        }
        /*
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout << dp[i][j] << ",";
            }
            cout << endl;
        }
        */
        return maxLen * maxLen;
    }
};

// Conciser solution
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        if(n==0) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int maxLen = 0;
        //Initialization
        for(int i=0; i<m ; ++i) {dp[i][0] = matrix[i][0] - '0'; maxLen = max(maxLen, dp[i][0]);}
        for(int i=0; i<n ; ++i) {dp[0][i] = matrix[0][i] - '0'; maxLen = max(maxLen, dp[0][i]);} 
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = matrix[i][j] - '0';
                if(dp[i][j] != 0) dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }

        return maxLen * maxLen;
    }
};

