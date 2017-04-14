/**************************************************************************
 * File Name : 373-FindKPairsWithSmallestSums.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-04-2017
 *
 * Last Modified : Fri Apr 14 18:36:51 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// k smallest --> main a min_heap
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(nums1.size() == 0 || nums2.size() == 0 || k<=0) return res;
        
        auto cmp = [&nums1, &nums2](pair<int, int>l, pair<int, int> r) { // define a lambda object
            return nums1[l.first] + nums2[l.second] > nums1[r.first] + nums2[r.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); // pass the lambda object to constructor
        pq.push({0,0});
        while(k-->0 && !pq.empty()){
            auto tmp = pq.top(); pq.pop();
            res.push_back({nums1[tmp.first], nums2[tmp.second]});
            if(tmp.first+1 < nums1.size()) pq.push({tmp.first+1, tmp.second});
            if(tmp.first == 0 && tmp.second+1 < nums2.size()) pq.push({tmp.first, tmp.second+1});
        }
        
        return res;
    }
};
