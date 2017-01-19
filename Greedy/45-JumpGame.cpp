/**************************************************************************
 * File Name : 45-JumpGame.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-01-2017
 *
 * Last Modified : Wed Jan 18 23:13:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Bulding the next level of BFS is a greedy searching process.
class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()<=1) return 0;
        
        int i=0, curMaxIdx = 0, nextMaxIdx = 0, counter = 0;

        while(curMaxIdx < nums.size()){
            counter++;
            for(;i<=curMaxIdx;i++){
                nextMaxIdx = max(nextMaxIdx, nums[i]+i);
                if(nextMaxIdx >= nums.size()-1) return counter;
            }
            curMaxIdx = nextMaxIdx;
        }
        
        return 0; 
    }
};
