/**************************************************************************
 * File Name : 80-RemoveDuplicatesFromSortedArrayII.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-02-2017
 *
 * Last Modified : Thu Feb 16 21:11:00 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Two pointer solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), i=0, j=0;
        for(;j<nums.size();j++){
            int len = 0;
            while(j < nums.size()-1 && nums[j] == nums[j+1]) {j++; len++;}
            nums[i++] = nums[j];
            if(len>0) nums[i++] = nums[j];
        }
        return i;
    }
};

// Conciser solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), i=0;
        for(int j=0; j<nums.size(); j++){
            if(j<2 || nums[j] > nums[i-2]) nums[i++] = nums[j];
        }
        return i;
    }
};
