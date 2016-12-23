/**************************************************************************
 * File Name : 26-RemoveDupsFromSortedArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-12-2016
 *
 * Last Modified : Thu Dec 22 19:48:56 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Implementation through naive vector operation.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //nums = vector<int> {1,1,1};
        if (nums.size()==1) return 1;
        int i;
        for(i=1;i<nums.size();i++){
            while (nums[i] == nums[i-1] && i<nums.size()) nums.erase(nums.begin()+i);
        }
        
        return nums.size();
    }
};


// Dynamically update the first k elements of the array in place. k is the number of unique elements
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size()==0) return 0;
        int i, marker=0;
        for(i=1;i<nums.size();i++){
            if(nums[i]!=nums[marker]) nums[++marker] = nums[i];
        }
        
        return ++marker;
    }
};
