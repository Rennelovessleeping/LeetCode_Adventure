/**************************************************************************
 * File Name : 249-GroupShiftedStrings.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-02-2017
 *
 * Last Modified : Thu Feb  9 00:29:28 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        vector<vector<string>> res;
        unordered_map<string, multiset<string>> map;
        
        for(auto str:strings){
            map[shiftStr(str)].insert(str);
        }
        
        for(auto x:map){
            res.push_back(vector<string> (x.second.begin(), x.second.end()));
        }
        
        return res;
        
    }
private:
    string shiftStr(string& s){
        string t;
        for(int i=1;i<s.size();i++){
            int diff = s[i] - s[i-1];
            if (diff < 0) diff += 26; // This is acturally the Periodic boundary conditions 
            t += 'a' + diff;
        }
        return t;
    }
};
