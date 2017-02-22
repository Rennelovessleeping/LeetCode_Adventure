/**************************************************************************
 * File Name : 15-3Sum.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-01-2017
 *
 * Last Modified : Wed Feb 22 12:49:04 2017
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

// Hashtable solution if one only need to judge whether such a triple exist or not
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp;
        vector<vector<int>> res;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(mp.find(nums[j]) != mp.end()) return true;
                else mp[-nums[i]-nums[j]] = {nums[i], nums[j]};
            }
        }
        
        return false;
    }
};

// Hashmap O(n^2) solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            mp.clear();
            for(int j=i+1; j<nums.size(); j++){
                if(mp.find(nums[j]) == mp.end()) mp[0-nums[i]-nums[j]] = nums[j];
                else {
                    res.push_back(vector<int> {nums[i], mp[nums[j]], nums[j]});
                    while(j+1<nums.size() && nums[j] == nums[j+1]) j++;
                }
        
            }
            
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        
        return res;
    }
};
