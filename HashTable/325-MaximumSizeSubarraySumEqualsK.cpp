/**************************************************************************
 * File Name : 325-MaximumSizeSubarraySumEqualsK.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-02-2017
 *
 * Last Modified : Thu Feb  9 20:19:33 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(n) solution using hashtable
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        int maxLen = 0, curSum = 0;
        unordered_map<int, int> pastSum;
        for(int i=0;i<nums.size();i++){
            curSum += nums[i];
            if(curSum == k) maxLen = i+1;
            else if(pastSum.find(curSum-k) != pastSum.end()) maxLen = max(maxLen, i-pastSum[curSum-k]);
            if( pastSum.find(curSum)==pastSum.end() ) pastSum[curSum] = i;
        }
        
        return maxLen;
    }
};

// brute force solution
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        int maxLen = 0, sum = 0;
        
        for(int i=0;i<nums.size();i++){
            for(int sum=0, j=i;j<nums.size();j++){
                sum += nums[j];
                if(sum == k) maxLen = max(maxLen, j-i+1);
            }
        }
        
        return maxLen;
    }
};


