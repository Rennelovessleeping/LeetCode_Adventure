/**************************************************************************
 * File Name : 164-MaximumGap.cpp
 *
 * Purpose :
 *
 * Creation Date : 04-04-2017
 *
 * Last Modified : Tue Apr  4 20:33:26 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Solution based on Bucket sort;
// max gap occurs at boundaries of buckets;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        vector<int> bucketMin(n-1, INT_MAX);
        vector<int> bucketMax(n-1, INT_MIN);
        
        int maxNum = INT_MIN, minNum = INT_MAX;
        for(const auto& x:nums){
            minNum = min(minNum, x);
            maxNum = max(maxNum, x);
        }
        
        // put # into buckets;
        int gap = (int) ceil((double)(maxNum - minNum) / (n-1)); 
        for(const auto& x:nums) {
            if(x == minNum || x == maxNum) continue;
            int idx = (x-minNum)/gap;
            bucketMin[idx] = min(x, bucketMin[idx]);
            bucketMax[idx] = max(x, bucketMax[idx]);
        }
        
        int res = INT_MIN, prev = minNum;
        for(int i=0; i<n-1; i++) {
            if(bucketMin[i] == INT_MAX) continue;
            res = max(res, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        
        return max(res, maxNum - prev);
    }
};
