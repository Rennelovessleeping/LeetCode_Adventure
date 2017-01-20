/**************************************************************************
 * File Name : 324-WiggleSortII.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-01-2017
 *
 * Last Modified : Fri Jan 20 15:34:35 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
//O(n) solution
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        
        for(int i=nums.size()-1, j=0, k=i/2+1;i>=0;i--){ // k-index of middle
            nums[i] = sorted[i&1 ? k++ : j++]; // interweaving;
        }
    }

};

// 3-way Partition
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        // Find a median.
        auto midptr = nums.begin() + len/2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid=*midptr;
        
        // calculate partition index such the value smaller than mid come first
        #define pIdx(i) (2*i+1)%(len|1)
        
        //DNF solution
        int i=0, j=0, k=len-1;
        while(j<=k){
            if(nums[pIdx(j)] > mid) swap(nums[pIdx(i++)], nums[pIdx(j++)]);
            else if(nums[pIdx(j)] < mid) swap(nums[pIdx(j)], nums[pIdx(k--)]);
            else j++;
        }
        
    }

};
