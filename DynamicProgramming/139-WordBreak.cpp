/**************************************************************************
 * File Name : 139-WordBreak.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-02-2017
 *
 * Last Modified : Sun Feb 12 22:35:15 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true; // "end" of a word
        
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j,i-j)) != wordDict.end() ) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};

