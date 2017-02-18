/**************************************************************************
 * File Name : 216-CombinationalSumIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-02-2017
 *
 * Last Modified : Fri Feb 17 20:04:45 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Backtracing solution
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, k, n);    
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& res, vector<int>& path, int k, int n){
        if(path.size() > k) return;
        if(path.size() == k && n == 0){
            res.push_back(path);
            return;
        }
        for(int i= path.empty() ? 1: path.back()+1; i<=9; ++i){
            path.push_back(i);
            dfs(res, path, k, n-i);
            path.pop_back();
        }
    }
    
};
