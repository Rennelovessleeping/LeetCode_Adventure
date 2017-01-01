/**************************************************************************
 * File Name : 198-HouseRobber.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-01-2017
 *
 * Last Modified : Sun Jan  1 12:55:54 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// raw DP solution
class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        vector<int> maxSoFar(nums.size(), 0);
        
        maxSoFar[0] = nums[0];
        maxSoFar[1] = max(nums[0], nums[1]);
        int maxMoney = maxSoFar[1];
        
        for(int i=2;i<nums.size();i++){
            maxSoFar[i] = max(maxSoFar[i-2]+nums[i], maxSoFar[i-1]);
            maxMoney = max(maxSoFar[i], maxMoney);
        }
        
        return maxMoney;
        
    }
};

// Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        
        // space optimization.
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        
        int twoAhead = nums[0];
        int oneAhead = max(nums[0], nums[1]);
        int maxMoney = INT_MIN;
        
        for(int i=2;i<nums.size();i++){
            maxMoney = max(maxMoney, max(twoAhead+nums[i], oneAhead));
            twoAhead = oneAhead;
            oneAhead = maxMoney;
        }
        
        return maxMoney;
        
    }
};

