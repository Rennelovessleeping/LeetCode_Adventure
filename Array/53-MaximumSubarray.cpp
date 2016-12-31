/**************************************************************************
 * File Name : 53-MaximumSubarray.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-12-2016
 *
 * Last Modified : Sat Dec 31 12:11:17 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        
        int len = nums.size();
        //if(len == 0) return 0;
        
        vector<int> maxSoFar(len, nums[0]);
        int maxSum = nums[0];
        
        for(int i=1;i<len;i++){
            maxSoFar[i] = max(0, maxSoFar[i-1]) + nums[i]; // state equation.
            maxSum = maxSoFar[i] > maxSum ? maxSoFar[i] : maxSum;
        }
        
        //for(auto a:maxSoFar) cout << a << ", "; cout << endl;
        return maxSum;
        
    }
};
