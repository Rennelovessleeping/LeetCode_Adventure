/**************************************************************************
 * File Name : 40-CombinationSumII.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-01-2017
 *
 * Last Modified : Sun Jan 15 21:01:25 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        for(int i=0;i<candidates.size();i++){
            helper(candidates[i], vector<int>{candidates[i]}, candidates, i, target);
            while( i+1 < candidates.size() && candidates[i+1] == candidates[i]) i++;
        }
        
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
        
        for(int j=i+1;j<candidates.size();j++){
            tmp.push_back(candidates[j]);
            helper(curSum+candidates[j], tmp, candidates, j, target);
            tmp.pop_back();
            while( j+1 < candidates.size() && candidates[j+1] == candidates[j]) j++;
        }
        
    }
    
};
