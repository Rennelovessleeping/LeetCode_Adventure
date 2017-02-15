/**************************************************************************
 * File Name : 90-SubsetII.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-02-2017
 *
 * Last Modified : Tue Feb 14 22:15:54 2017
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
