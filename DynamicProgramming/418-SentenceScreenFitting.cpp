/**************************************************************************
 * File Name : 418-SentenceScreenFitting.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-04-2017
 *
 * Last Modified : Thu Apr  6 21:36:41 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> dp(n, 0); // dp[i] : absolute ending word if we start a line by sentences[i];
        
        for(int i=0, pos=0, len=0; i<n; i++) {
            if(i>0 && len > 0) len -= sentence[i-1].length() + 1; // dont set len = 0; 
            while(len + sentence[pos % n].length() <= cols) len += sentence[pos++ % n].length() + 1; // 1 for space
            dp[i] = pos;
        }
        
        int word_cnt = 0;
        for(int i=0, k=0; i<rows; i++) {
            word_cnt += dp[k] - k;
            k = dp[k] % n;
        }
        
        return word_cnt/n;
    }
};
