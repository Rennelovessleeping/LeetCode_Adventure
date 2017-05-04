/**************************************************************************
 * File Name : 376-WiggleSequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 04-05-2017
 *
 * Last Modified : Thu May  4 13:48:12 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int inc = 1, dec = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) inc = dec + 1; // increase the wiggle sequence ending with increasing pair by 1; 
            else if(nums[i] < nums[i-1]) dec = inc + 1;
        }
        
        return min(n, max(inc, dec));
    }
};

