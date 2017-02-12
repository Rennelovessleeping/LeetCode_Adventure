/**************************************************************************
 * File Name : 56-MergeIntervals.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-02-2017
 *
 * Last Modified : Sat Feb 11 22:29:36 2017
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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size()==0) return res;
        sort(intervals.begin(), intervals.end(), [](Interval& l, Interval& r){return l.start < r.start;});
        
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start <= res.back().end){
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else res.push_back(intervals[i]);
        }
        
        return res;
    }
};

