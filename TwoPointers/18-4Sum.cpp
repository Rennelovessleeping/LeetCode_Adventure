/**************************************************************************
 * File Name : 18-4Sum.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-12-2016
 *
 * Last Modified : Wed Feb 22 13:28:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Hashtable solution using 3sum + 2sum O(n^3) solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            for(int k=nums.size()-1 ; k-i >2; k--){
                unordered_map<int, int> mp;
                for(int j=i+1; j<k; j++){
                    if (mp.find(nums[j]) == mp.end()) mp[target-nums[i]-nums[k]-nums[j]] = nums[j];
                    else {
                        vector<int> quadruplet = {nums[i], mp[nums[j]], nums[j],nums[k]};
                        res.push_back(quadruplet);
                        while(j+1 < k && nums[j] == nums[j+1]) j++;
                    }
                }
                while(k-1-i >2 && nums[k] == nums[k-1]) k--;
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        
        return res;
    }
};

// Two Pointer solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        for(int i=0; i<len-3; i++) {
            for(int j=i+1; j<len-2; j++) {
                int k = j+1, last = len-1;
                while(k<last){
                    int tmpSum = nums[i] + nums[j] + nums[k] + nums[last];
                    if(tmpSum == target) {
                        res.push_back(vector<int> {nums[i], nums[j], nums[k], nums[last]});
                        while(last > k && nums[last] == nums[last-1]) last--;
                        while(last > k && nums[k] == nums[k+1]) k++;
                        last--; k++;
                        
                    }
                    else if(tmpSum > target) {
                        while(last > k && nums[last] == nums[last-1]) last--;
                        last--;
                    }
                    else {
                        while(last > k && nums[k] == nums[k+1]) k++;
                        k++;
                    }
                    
                }
                while(j+1 < len-2 && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < len-3 && nums[i] == nums[i+1]) i++;
        }
        
        return res;
    }
};
