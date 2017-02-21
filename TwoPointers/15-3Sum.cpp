/**************************************************************************
 * File Name : 15-3Sum.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-01-2017
 *
 * Last Modified : Sat Feb 18 20:22:05 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> solutionSet;
        if(nums.size()<3) return solutionSet;
        
        int len=nums.size();
        sort(nums.begin(), nums.end());
        int i,j,k;
        
        for(i=0;i<len;i++){
            j = i+1;
            k = len-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    solutionSet.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0){ 
                    while(j<k && nums[k]==nums[k-1]) k--;
                    k--;
                }
                else {
                    while(j<k && nums[j]==nums[j+1]) j++;
                    j++;
                }
                
            }
            
            while(i<len && nums[i]==nums[i+1]) i++;
        }
        
        return solutionSet;
        
    }
};
