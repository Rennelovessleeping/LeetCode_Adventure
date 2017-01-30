/**************************************************************************
 * File Name : 209-MinimumSizeSubarraySum.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-01-2017
 *
 * Last Modified : Sun Jan 29 18:52:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), front, back;
        int res = INT_MAX, sum=0, start=0;
        for(int i=0; i<len; i++){
            sum += nums[i];
            while(sum >= s){
                res = min(res, i-start+1);
                sum -= nums[start++];
            }

        }
        return res==INT_MAX ? 0 : res;
        
    }
};
