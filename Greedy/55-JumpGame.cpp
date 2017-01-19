/**************************************************************************
 * File Name : 55-JumpGame.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-01-2017
 *
 * Last Modified : Wed Jan 18 22:38:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Simply keep maximizing the reachable index sofar until it's become smaller than current Idx;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int i, maxIdx;
        for(i=0, maxIdx=0;i<nums.size() && i<=maxIdx;i++){
            maxIdx = max(i+nums[i], maxIdx);
        }
        
        return i==nums.size();
    }
};
