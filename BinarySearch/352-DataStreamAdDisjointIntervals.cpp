/**************************************************************************
 * File Name : 352-DataStreamAdDisjointIntervals.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-04-2017
 *
 * Last Modified : Sat Apr  8 13:30:15 2017
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
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() { }
    
    void addNum(int val) {
        int start = val, end = val;
        auto it = st.lower_bound(Interval(start, end));
        
        if(it != st.begin() && (--it)->end+1 < val) it++;
        while(it != st.end() && it->start-1 <= val && it->end+1 >= val) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it); // return iterator pointing to the element following the erased one
        }
        st.insert(it, Interval(start, end)); // optimized insertion
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res(st.begin(), st.end());
        return res;
    }
    
private:
    struct cmp {
        bool operator() (const Interval& l, const Interval& r) {return l.start < r.start;}
    };
    
    set<Interval, cmp> st;
    
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
