/**************************************************************************
 * File Name : 692-TopKFrequentWords.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-10-2017
 *
 * Last Modified : Sat Oct 14 15:18:30 2017
 *
 * Created By :  Renee Bai
**************************************************************************/
// Bucket Sort solution O(n)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(k <= 0) return {};
        int n = words.size();
        unordered_map<string, int> mp;
        for(auto word:words) mp[word]++;
        
        vector<vector<string>> bucket(n+1, vector<string> {});
        for(auto& item:mp) bucket[item.second].push_back(item.first);
        
        vector<string> res;
        for(int i=n; i>0; i--) {
            if(bucket[i].empty()) continue;
            sort(bucket[i].begin(), bucket[i].end());
            for(auto word:bucket[i]){
                res.push_back(word);
                if(res.size() == k) return res;
            }
        }
        
        return res;
    }
};


// Heap Sort O(nlog(k)).
class Solution {
public:
    struct cmp{
        bool operator() (const pair<int, string>& l, const pair<int ,string>& r) {
            return l.first > r.first || (l.first == r.first && l.second < r.second);
        }    
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        if(k <= 0) return {};
        int n = words.size();
        unordered_map<string, int> mp;
        for(auto word:words) mp[word]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq; // minheap
        for(const auto& item:mp) {
            pq.push({item.second, item.first});
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> res;
        while(!pq.empty()) {
            auto tmp = pq.top(); pq.pop();
            res.push_back(tmp.second);
        }
        
        return vector<string> (res.rbegin(), res.rend());
    }
};
