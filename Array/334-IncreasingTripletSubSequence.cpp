/**************************************************************************
 * File Name : 334-IncreasingTripletSubSequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-02-2017
 *
 * Last Modified : Wed Feb 15 18:20:04 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, medium = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= small) small = nums[i];
            else if(nums[i] <= medium) medium = nums[i];
            else return true;
        }
        
        return false;
    }
    
};

// DFS solution: terrible when we have a long descending sorte array;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> path{};
        if(nums.size()<3) return false;
        return dfs(nums, path, 0);
    }
    
private:
    bool dfs(vector<int>&nums, vector<int> path, int pos){
        if(path.size()==3) return true;
        if(pos == nums.size()) return false;
        
        for(int i=pos; i<nums.size();i++){
            if( path.back()<nums[i]) {
                path.push_back(nums[i]);
                if(dfs(nums, path, i+1)) return true;
                path.pop_back();
            }
        }
        
        return false;
    }
};
