/**************************************************************************
 * File Name : 673-NumberOfLongestIncreasingSubsequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-09-2017
 *
 * Last Modified : Fri Sep 22 12:48:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Similar Idea to LC300, but we need to record the cnt of longest subsequence ending at each nums[i]
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, res = 0;
        vector<int> len(n,1), cnt(n,1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] <= nums[j]) continue;                
                if(len[i] == len[j]+1) cnt[i] += cnt[j];
                else if(len[i] < len[j]+1) {
                    len[i] = len[j]+1;
                    cnt[i] = cnt[j];
                }
            }
            
            if(len[i] == maxLen) res += cnt[i];
            else if(len[i] > maxLen) {
                maxLen = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
};
