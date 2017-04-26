/**************************************************************************
 * File Name : 248-StrobogrammaticNumberIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-04-2017
 *
 * Last Modified : Tue Apr 25 20:55:32 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    long lower, upper;
    int strobogrammaticInRange(string low, string high) {
        lower = stol(low), upper = stol(high);
        int res = 0;
        
        for(int n = low.length(); n <= high.length(); n++){
            string cand(n, ' ');
            dfs(res, cand, 0, n-1);
        }
        return res;
    }
    
    unordered_map<char, char> mp = {{'0','0'}, {'1','1'}, {'8','8'}, {'6','9'}, {'9','6'}};
    void dfs(int& res, string& cand, int left, int right) {
        if(left > right) {
            if(stol(cand) >= lower && stol(cand) <= upper) res++;
            return;
        }
        
        for(auto item:mp) {
            cand[left] = item.first, cand[right] = item.second;
            if(cand.length() > 1 && cand[0] == '0') continue;
            if(left == right && item.first != item.second) continue;
            dfs(res, cand, left+1, right-1);
        }
    }
    
};
