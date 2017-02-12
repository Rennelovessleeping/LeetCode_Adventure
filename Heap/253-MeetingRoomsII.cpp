/**************************************************************************
 * File Name : 253-MeetingRoomsII.cpp
 *
 * Purpose :
 *
 * Creation Date : 11-02-2017
 *
 * Last Modified : Sat Feb 11 22:03:39 2017
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
    struct minComp{
        bool operator() (const Interval& l, const Interval& r) {return l.end > r.end;}
    };
    
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval& l, Interval& r){return l.start < r.start;});
        priority_queue<Interval, vector<Interval>, minComp> pq;
        
        pq.push(intervals[0]);
        cout << pq.top().start << ", " << pq.top().end << endl;
        for(int i=1;i<intervals.size();i++){
            Interval cur = pq.top();
            pq.pop();
            if(intervals[i].start >= cur.end){
                cur.end = intervals[i].end;
            }
            else pq.push(intervals[i]);
            pq.push(cur);
        }
        
        return pq.size();
        
    }
    
};
