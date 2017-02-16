/**************************************************************************
 * File Name : 128-LongestConsecutiveSequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-02-2017
 *
 * Last Modified : Wed Feb 15 20:46:16 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> mp; //{boundary, maxLength based on that boundary}
        int res = 0;
        for(auto x:nums){
            if(mp.find(x) != mp.end()) continue;
            
            int left = (mp.find(x-1) == mp.end() ? 0 : mp[x-1]);
            int right = (mp.find(x+1) == mp.end() ? 0 : mp[x+1]);

            int newLen = left + 1 + right;
            mp[x] = newLen;
            
            res = max(newLen, res);
            mp[x-left] = newLen;
            mp[x+right] = newLen;
        }
        
        return res;
    }
};
