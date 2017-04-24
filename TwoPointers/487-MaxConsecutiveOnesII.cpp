/**************************************************************************
 * File Name : 487-MaxConsecutiveOnesII.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-04-2017
 *
 * Last Modified : Sun Apr 23 19:31:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, q = -1; // q stores the idx of 0 in [l, h]
        for(int l=0, h=0; h<nums.size(); h++) {
            if(nums[h] == 0) {
                l = q+1;
                q = h;
            }
            res = max(res, h-l+1);
        }
        return res;
    }
};
