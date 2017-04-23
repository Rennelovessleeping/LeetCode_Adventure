/**************************************************************************
 * File Name : 362-DesignHitCounter.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-04-2017
 *
 * Last Modified : Sun Apr 23 13:47:24 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use Buckets for the 5min = 300s.
class HitCounter {
private:
    int times[300] = {0};
    int hits[300] = {0};
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int idx = timestamp % 300;
        if(times[idx] != timestamp) {
            times[idx] = timestamp;
            hits[idx] = 1;
        }
        else hits[idx]++;
        
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res = 0;
        for(int i=0; i< 300; i++) {
            res += timestamp - times[i] >= 300 ? 0 : hits[i];
        }
        return res;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
