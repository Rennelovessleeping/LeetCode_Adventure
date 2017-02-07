/**************************************************************************
 * File Name : 78-Subsets.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-02-2017
 *
 * Last Modified : Mon Feb  6 20:38:43 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Backtracing solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        helper(nums, seq, 0, res);
        return res;
    }

private:
    void helper(vector<int>& nums, vector<int>& seq, int idx, vector<vector<int>>& res){
        res.push_back(seq);
        if(idx == nums.size()) return;
        
        for(int i=idx;i<nums.size();i++){
            seq.push_back(nums[i]);
            helper(nums, seq, i+1, res);
            seq.pop_back();
        }
    }
    
};

// Bit manipulation
// note that the total combination is 2^nums.size() since the numbers are unique
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsetNum = pow(2, nums.size());
        vector<vector<int>> res(subsetNum, vector<int>{});
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<subsetNum;j++){
                if((j>>i) & 1) res[j].push_back(nums[i]);
            }
        }
        
        return res;
    }
    
};

