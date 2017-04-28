/**************************************************************************
 * File Name : 131-PalindromeParitioning.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-04-2017
 *
 * Last Modified : Thu Apr 27 20:12:17 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(res, path, s, 0);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& path, const string& s, int pos) {
        if(pos == s.length()) {
            res.push_back(path);
            return;
        }
        
        for(int i=pos; i<s.size(); i++){
            if(isPalindrome(s, pos, i)) {
                // cout << s.substr(pos, i-pos+1) << endl;
                path.push_back(s.substr(pos, i-pos+1));
                dfs(res, path, s, i+1);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        
        return true;
    }
};
