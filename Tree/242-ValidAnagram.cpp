/**************************************************************************
 * File Name : 242-ValidAnagram.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-12-2016
 *
 * Last Modified : Thu Dec 22 00:00:13 2016
 *
 * Created By :  
**************************************************************************/
// Sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s==t;
        
        
    }
};


// Using Dict

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) return false;
        unordered_map<char, int> countDict;
        
        for(int i=0;i<s.size();i++){
            countDict[s[i]]++;
            countDict[t[i]]--;
        }
        
        for(auto const& a:countDict){
            if(a.second) return false;
        }
        
        return true;
        
    }
};
