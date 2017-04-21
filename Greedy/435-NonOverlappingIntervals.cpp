/**************************************************************************
 * File Name : 435-NonOverlappingIntervals.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-04-2017
 *
 * Last Modified : Thu Apr 20 22:00:57 2017
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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0) return 0;
        auto cmp = [](const Interval& l, const Interval& r){ return l.end < r.end; };
        sort(intervals.begin(), intervals.end(), cmp);
        
        int cnt = 1; // # of maximum non-overlapping intervals
        int end = intervals[0].end;
        for(int i=0; i<intervals.size(); i++) {
            if(intervals[i].start >= end) {
                end = intervals[i].end;
                cnt++;
            }
        }
        
        return n - cnt;
    }
};
