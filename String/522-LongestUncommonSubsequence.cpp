/**************************************************************************
 * File Name : 522-LongestUncommonSubsequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-04-2017
 *
 * Last Modified : Sun Apr 16 16:03:57 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        // Only the unique strs are candidates;
        unordered_map<string, int> mp;
        for(const auto& s:strs) mp[s]++;
        
        vector<pair<string, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](pair<string, int>&l, pair<string, int>&r){return l.first.length() > r.first.length();});
        
        for(int i=0; i<v.size(); i++) {
            if(v[i].second == 1) {
                int j = 0;
                for(; j<i; j++) {
                    if(isSubsequence(v[i].first, v[j].first)) break;
                }
                if (j==i) return v[i].first.length();
            }
        }
        
        return -1;
    }
    
    bool isSubsequence(const string& s1, const string& s2) {
        int i = 0, j = 0;
        for(; i<s1.size(); i++, j++) {
            while(j<s2.size() && s2[j] != s1[i]) j++;
            if(j == s2.size()) return false;
        }
        return true;
    }
};
