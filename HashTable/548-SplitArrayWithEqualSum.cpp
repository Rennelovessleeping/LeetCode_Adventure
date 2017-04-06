/**************************************************************************
 * File Name : 548-SplitArrayWithEqualSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 04-04-2017
 *
 * Last Modified : Tue Apr  4 19:34:25 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 7) return false;
        
        vector<int> prefix(n+1, 0);
        for(int i=1; i<=n; i++) prefix[i] = prefix[i-1] + nums[i-1];
        
        for(int j=3; j<n-3; j++) {
            unordered_map<int, int> mp; // {quarter sum, i}
            for(int i=1; i<j-1; i++) {
                if(prefix[i] == prefix[j] - prefix[i+1]) mp[prefix[i]] = i;
            }
            for(int k=j+1; k<n-1; k++) {
                if(prefix[k] - prefix[j+1] == prefix[n]-prefix[k+1] && mp.find(prefix[k] - prefix[j+1]) != mp.end()) return true;
            }
        }
        
        return false;
    }
};
