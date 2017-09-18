/**************************************************************************
 * File Name : 90-SubsetII.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-02-2017
 *
 * Last Modified : Mon Sep 18 13:19:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Backtracing solution
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, res, path, 0);
        return res;
    }
    
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int pos){
        res.push_back(path);
        if(pos == nums.size()) return;
        
        for(int i=pos;i<nums.size();i++){
            if(i==pos || nums[i] != nums[i-1]){
                path.push_back(nums[i]);
                dfs(nums, res, path, i+1);
                path.pop_back();
            }
            
        }
    }
};

// Iterative Solution
// If we want to insert an element which is a dup, we can only insert it after the newly inserted elements from last step.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        int startIdx = 0, len = 0;
        for(int i=0; i<nums.size(); i++) {
            startIdx = i>0 && nums[i] == nums[i-1] ? len : 0;
            len = res.size();
            for(int j=startIdx; j<len; j++) {
                auto tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
