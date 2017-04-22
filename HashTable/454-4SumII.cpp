/**************************************************************************
 * File Name : 454-4SumII.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-04-2017
 *
 * Last Modified : Sat Apr 22 14:26:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp1, mp2;
        helper(A, B, mp1);
        helper(C, D, mp2);
        
        int res  = 0;
        for(auto it1 = mp1.begin(); it1 != mp1.end(); it1++) {
            auto it2 = mp2.find(-it1->first);
            res += it2 == mp2.end() ? 0 : it1->second * it2->second;
        }
        
        return res;
    }
    
    void helper(const vector<int>& vec1, const vector<int>& vec2, unordered_map<int, int>& mp) {
        int n = vec1.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) mp[vec1[i]+vec2[j]]++;
        }
   
