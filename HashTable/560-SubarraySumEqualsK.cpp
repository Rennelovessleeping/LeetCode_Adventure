/**************************************************************************
 * File Name : 560-SubarraySumEqualsK.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 22:50:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum; // {presum:count}
        presum[0] = 1;
        
        int sum = 0, res = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(presum.find(sum-k) != presum.end()) res += presum[sum-k];
            presum[sum]++;
        }
        
        return res;
    }
};
