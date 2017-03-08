/**************************************************************************
 * File Name : 254-FactorCombinations.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-03-2017
 *
 * Last Modified : Tue Mar  7 19:28:07 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Efficient algorithm to find all prime factors of an integer
// start from 2, 3 ... sqrt(n)
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, n);
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& res, vector<int>& path, int n){
        int i = path.empty() ? 2 : path.back();
        for(;i<=n/i;i++){
            if(n%i == 0){
                path.push_back(i);
                path.push_back(n/i);
                res.push_back(path);
                path.pop_back();
                dfs(res, path, n/i);
                path.pop_back();
            }
        }
    }
};

