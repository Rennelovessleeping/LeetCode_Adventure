/**************************************************************************
 * File Name : 16-3SumClosest.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-12-2016
 *
 * Last Modified : Wed Dec 28 00:19:38 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Sort + Brute search 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int len= nums.size()-2 ;
        int sum = nums[0] + nums[1] + nums[2];
        int diff;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len+1;j++){
                for(int k=j+1;k<len+2;k++){
                    diff = abs(nums[i]+nums[j]+nums[k]-target);
                    if(diff==0) return nums[i]+nums[j]+nums[k];
                    sum = abs(sum-target) < diff ? sum : nums[i]+nums[j]+nums[k];
                } 
            }
        }
        
        return sum;
        
    }
};

// Refine
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        /*
        // test case
        nums = {1,1,1,0};
        target = -100;
        */
        
        int len= nums.size() ;
        sort(nums.begin(), nums.end());
        
        int sum, prevSum = nums[0]+nums[1]+nums[2];
        for(int i=0;i<len-2;i++){
            int k = len-1;
            int j = i+1;
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return sum;
                if( abs(prevSum-target) > abs(sum-target) ) prevSum = sum;
                sum < target ? j++ : k--;
            }
        }
        
        return prevSum;
        
    }
};

