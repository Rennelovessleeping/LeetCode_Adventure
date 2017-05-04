/**************************************************************************
 * File Name : 280-WiggleSort.cpp
 *
 * Purpose :
 *
 * Creation Date : 04-05-2017
 *
 * Last Modified : Thu May  4 13:31:44 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// The following naive greedy solution works due to the weak requirement of order
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++) {
            if(((i&1) && nums[i] < nums[i-1]) || (!(i&1) && nums[i] > nums[i-1])) swap(nums[i], nums[i-1]);
        }
    }
};
