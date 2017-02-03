/**************************************************************************
 * File Name : 287-FindDuplicateNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-02-2017
 *
 * Last Modified : Thu Feb  2 23:47:54 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// The list is convertible to a cycled list
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // Same as Q142, move slow and fast before cycling
        int slow = nums[0], fast = nums[nums[0]];
        
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        fast = 0;
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;   
    }
};
