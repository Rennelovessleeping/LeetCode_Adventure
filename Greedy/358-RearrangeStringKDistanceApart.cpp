/**************************************************************************
 * File Name : 358-RearrangeStringKDistanceApart.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-02-2017
 *
 * Last Modified : Sat Feb 25 20:55:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// The idea is to use cache to temporially store which elements to push back after current k window
class Solution {
public:
    string rearrangeString(string s, int k) {
        
        string res = "";
        if(k==0) return s;
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int>mp;
        int len = s.size();
        
        for(auto ch:s) mp[ch]++;
        for(auto item:mp) pq.push({item.second, item.first});
        
        while(!pq.empty()){
            vector<pair<int, char>> cache;
            int count = min(k, len);
            for(int i=0; i<count; i++){ // edge case k = 0, the loops will never stop
                if (pq.empty()) return ""; // e.g. less than k distinct chars are remaining;
                auto tmp = pq.top();
                pq.pop();
                res += tmp.second;
                len--;
                if(--tmp.first>0) cache.push_back(tmp);
            }
            for(auto item:cache) pq.push(item);
        }
        
        return res;
    }
};
