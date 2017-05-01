/**************************************************************************
 * File Name : 336-PalindromePairs.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-04-2017
 *
 * Last Modified : Thu Apr 27 19:59:15 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++) mp[words[i]] = i;
        
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<=words[i].size(); j++) {
                string head = words[i].substr(0,j);
                string tail = words[i].substr(j);
                if(isPalindrome(head)){
                    string tmp = tail;
                    reverse(tmp.begin(), tmp.end());
                    if(mp.find(tmp) != mp.end() && mp[tmp] != i) res.push_back({mp[tmp], i});
                } 
                
                if(isPalindrome(tail)){
                    string tmp = head;
                    reverse(tmp.begin(), tmp.end());
                    // check tail.size() to avoid duiplicates generated by pairs ["abcd","dcba"]
                    // generate "abcddcba" from iteration over "abcd"
                    // generate "dcbaabcd" from iteration over "dcba"
                    if(mp.find(tmp) != mp.end() && mp[tmp] != i && tail.size()!=0) res.push_back({i, mp[tmp]});
                } 
            }
        }
        
        return res;
    }
    
    bool isPalindrome(const string& s){
        int i=0, j=s.length()-1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
};