/**************************************************************************
 * File Name : 347-TopkFrequentElements.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-01-2017
 *
 * Last Modified : Sat Feb 25 23:19:33 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        //Build HashTable
        unordered_map<int, int> mapNums;
        for(int i=0;i<nums.size();i++){
            mapNums[nums[i]]++;
        }
        
        // Select the top k element;
        priority_queue<pair<int,int>> pq;
        for(auto x:mapNums){
            pq.push(make_pair(x.second, x.first));
            if(pq.size() > mapNums.size()-k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
        
    }
};

// Use min_heap O(nlog(k)) solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min_heap
        vector<int> res;
        
        for(auto n:nums) mp[n]++;
        for(auto item:mp){
            pq.push({item.second, item.first});
            if(pq.size() > k) pq.pop();
        }
        
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
        
};
