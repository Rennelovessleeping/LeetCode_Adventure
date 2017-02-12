/**************************************************************************
 * File Name : 57-InsertInterval.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-02-2017
 *
 * Last Modified : Sat Feb 11 23:43:45 2017
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int i;
        for(i=0;i<intervals.size();i++){
            if(intervals[i].end < newInterval.start) res.push_back(intervals[i]);
            else if(intervals[i].start > newInterval.end) break;
            else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        
        res.push_back(newInterval);
        for(;i<intervals.size();i++) res.push_back(intervals[i]);
        return res;
    }
};

// Actually does not need to do the binary search...
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty()) return vector<Interval> {newInterval};
        
        int pos = insert_pos(intervals, newInterval.start);
        vector<Interval> res;
        for(int i=0;i<pos;i++) res.push_back(intervals[i]);
        
        if(pos == 0 || res.back().end < newInterval.start) res.push_back(newInterval);
        else res.back().end = max(res.back().end, newInterval.end);
        
        // Merge intervals
        for(int i=pos;i<intervals.size();i++){
            if( intervals[i].start > res.back().end) res.push_back(intervals[i]);
            else if (intervals[i].start <= res.back().end) res.back().end = max(res.back().end, intervals[i].end);
        }
        
        return res;
    }
    
private:
    int insert_pos(vector<Interval>& intervals, int x){
        int left = 0, right = intervals.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(intervals[mid].start == x) return mid;
            if(intervals[mid].start < x) left = mid + 1;
            else right = mid - 1;
        }
        return left; 
    }
    
};
