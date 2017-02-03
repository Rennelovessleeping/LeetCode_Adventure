/**************************************************************************
 * File Name : 474-OnesAndZeros.cpp
 *
 * Purpose :
 *
 * Creation Date : 03-02-2017
 *
 * Last Modified : Fri Feb  3 17:50:03 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // sort(strs.begin(), strs.end(), [](string& s, string& t){return s.length() < t.length();});
        vector<vector<int>> dp(m+1, vector<int> (n+1,0)); // dp[i][j] is the max number formation of strings;
        for(auto str:strs){
            int ones = 0, zeros=0;
            for(int i=0;i<str.size();i++) str[i] == '0' ? zeros++ : ones++;
            
            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    // when passing into the inside of loop, current str must can be formed;
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            }
            
        }
        
        return dp[m][n];
    }
};
