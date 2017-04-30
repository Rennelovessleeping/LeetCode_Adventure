/**************************************************************************
 * File Name : 561-ArrayPartition.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 12:47:46 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i=0; i<n; i+=2) res += nums[i];
        return res;
    }
};
