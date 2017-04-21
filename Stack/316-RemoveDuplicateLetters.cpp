/**************************************************************************
 * File Name : 316-RemoveDuplicateLetters.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-04-2017
 *
 * Last Modified : Thu Apr 20 20:45:58 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Maintaining a monotonic stack for the remaing letters in the string
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> mp(256, 0);
        vector<bool> visited(256, false);
        string res = "0"; // dummpy min value
        
        for(auto c:s) mp[c]++;
        
        for(auto c:s){
            mp[c]--;
            if(visited[c]) continue;
            while(c < res.back() && mp[res.back()]) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        
        return res.substr(1);
    }
};
