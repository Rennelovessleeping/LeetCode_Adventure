/**************************************************************************
 * File Name : 436-FindRightInterval.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-04-2017
 *
 * Last Modified : Sat Apr  8 12:23:24 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> mp;
        for(int i=0; i<intervals.size(); i++) mp[intervals[i].start] = i;
        
        vector<int> res;
        for(int i=0; i<intervals.size(); i++) {
            auto it = mp.lower_bound(intervals[i].end);
            if(it != mp.end()) res.push_back(it->second);
            else res.push_back(-1);
        }
        return res;
    }
};
