/**************************************************************************
 * File Name : 18-4Sum.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-12-2016
 *
 * Last Modified : Wed Dec 28 00:20:09 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        //nums = {0,0,0,0}; target = 0;
        //nums = {-1,2,2,-5,0,-1,4}; target = 3;
        
        vector<vector<int>> solutionSet;
        sort(nums.begin(), nums.end());
        
        int len = nums.size(), sum;
        int i,j,k, last;
        
        for(i=0;i<len-3;i++){
            for(j=i+1;j<len-2;j++){
                k = j + 1;
                last = len - 1;

                while(k<last){
                    sum = nums[i] + nums[j] + nums[k] +nums[last];
                    if(sum == target){
                        solutionSet.push_back({nums[i], nums[j], nums[k], nums[last]});
                        while(k<last && nums[k+1] == nums[k]) k++;
                        while(k<last && nums[last-1] == nums[last]) last--;
                    }
                    sum < target ? k++ : last--;
                }
                
                while(j<len-2 && nums[j+1] == nums[j]) j++;
            }
            
            while(i<len-3 && nums[i+1] == nums[i]) i++;
        }
        
        return solutionSet;
    }
};
