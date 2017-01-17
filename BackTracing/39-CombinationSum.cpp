/**************************************************************************
 * File Name : 39-CombinationSum.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-01-2017
 *
 * Last Modified : Sun Jan 15 20:56:21 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        helper(0, vector<int>(), candidates, 0, target);
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    void helper(int curSum, vector<int> tmp, vector<int>& candidates, int i, int target){
        if(curSum > target) return;
        if(curSum == target){
            ans.push_back(tmp);
            return;
        }
        
        for(int j=i;j<candidates.size();j++){
            tmp.push_back(candidates[j]);
            helper(curSum+candidates[j], tmp, candidates, j, target);
            tmp.pop_back();
        }
        
    }
    
};
