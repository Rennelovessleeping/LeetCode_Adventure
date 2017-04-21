/**************************************************************************
 * File Name : 452-MininumNumberOfArrowsToBurstBalloon.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-04-2017
 *
 * Last Modified : Thu Apr 20 22:15:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n==0) return 0;
        auto cmp = [](const pair<int, int>& l, const pair<int,int>& r){ return l.second < r.second; };
        sort(points.begin(), points.end(), cmp);
        
        int cnt = 1; // # of maximum non-overlapping intervals
        int end = points[0].second;
        for(int i=1; i<points.size(); i++) {
            if(points[i].first > end) {
                end = points[i].second;
                cnt++;
            }
        }
        
        return cnt;

    }
};
