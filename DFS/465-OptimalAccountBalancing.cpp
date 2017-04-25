/**************************************************************************
 * File Name : 465-OptimalAccountBalancing.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-04-2017
 *
 * Last Modified : Mon Apr 24 22:20:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<long> debt; // non-zero balances;
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long> mp; // personal balances
        for(const auto& t:transactions){
            mp[t[0]] -= t[2];
            mp[t[1]] += t[2];
        }
        
        for(const auto& item:mp) {
            if (item.second) debt.push_back(item.second);
        }
        
        return dfs(0,0);
    }
    
    int dfs(int start, int cnt){
        while(start < debt.size() && !debt[start]) start++;
        int res = INT_MAX;
        for(int i=start+1, prev=0; i<debt.size(); i++) {
            if(debt[i] != prev && debt[i] * debt[start] < 0){
                debt[i] += debt[start];
                res = min(res, dfs(start+1, cnt+1)); // one trans to clear debt[start]
                prev = debt[i] -= debt[start];
            }
        }
        
        return res == INT_MAX ? cnt : res;
    }
};
