/**************************************************************************
 * File Name : 485-MaxConsecutiveOnes.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-02-2017
 *
 * Last Modified : Tue Feb  7 19:45:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Two-pointer solution
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i,j, maxLength=0;
        for(i=0;i<nums.size();i=j){
            while(i<nums.size() && nums[i] == 0) i++;
            for(j=i;j<nums.size() && nums[j]==1;j++) {}
            maxLength = max(maxLength, j-i);
        }
        return maxLength;
    }
};

// Conciser solution:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxSoFar = 0, maxLength = 0;
        for(int i=0;i<nums.size();i++){
            maxLength = max(maxLength, maxSoFar = nums[i]==0 ? 0 : 1+maxSoFar);
        }
        return maxLength;
    }
};
