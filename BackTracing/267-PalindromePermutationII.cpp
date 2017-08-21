/**************************************************************************
 * File Name : 267-PalindromePermutationII.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-05-2017
 *
 * Last Modified : Sat May  6 11:37:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> mp;
        
        // count chars
        int odd = 0;
        for(const char& ch:s) {
            mp[ch]++;
            odd += (mp[ch] & 1) ? 1 : -1;
        }
        if(odd > 1) return res;
        
        vector<char> cand;
        string mid;
        
        for(const auto item:mp) {
            if(item.second & 1) mid += item.first;
            for(int i=0; i<item.second/2; i++) cand.push_back(item.first);
        }
        
        // search for all permutations
        vector<bool> visited(cand.size(), false);
        string path;
        dfs(res, cand, visited, path, mid);
        
        return res;
    }
    
    void dfs(vector<string>& res, const vector<char>& cand, vector<bool>& visited, string& path, string mid) { // generate permutation
    
        if(path.size() == cand.size()) {
            res.push_back(path + mid + string(path.rbegin(), path.rend()));
            return;
        }
        
        for(int i=0; i<cand.size(); i++) {
            if(visited[i]) continue;
            
            path.push_back(cand[i]);
            visited[i] = true;
            dfs(res, cand, visited, path, mid);
            path.pop_back();
            visited[i] = false;
            
            while(i+1<cand.size() && cand[i] == cand[i+1]) i++; // avoid duplication;
        }
    }
};
