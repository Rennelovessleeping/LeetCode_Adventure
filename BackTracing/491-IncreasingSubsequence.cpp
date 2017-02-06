/**************************************************************************
 * File Name : 491-IncreasingSubsequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 05-02-2017
 *
 * Last Modified : Sun Feb  5 22:32:43 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS solution
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        if(nums.size()<2) return vector<vector<int>> {};
        vector<int> path;
        dfs(nums, path, 0);
        return res;
    }
    
private:
    vector<vector<int>> res;
    
    void dfs(vector<int>& nums, vector<int>& path, int idx){
        if(path.size()>1) res.push_back(path);
        //Dont define visited as global private variable. Then pattern like 4,7,7 can be kept while 4,7... will not be searched twice
        unordered_set<int> visited;
        
        for(int i=idx;i<nums.size();i++){
            if((path.empty() || nums[i] >= path.back()) && visited.find(nums[i])==visited.end()){
                path.push_back(nums[i]);
                dfs(nums, path, i+1);
                path.pop_back();
                visited.insert(nums[i]);
            }
        }
        
    }
};


