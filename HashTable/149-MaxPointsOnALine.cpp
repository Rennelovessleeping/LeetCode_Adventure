/**************************************************************************
 * File Name : 149-MaxPointsOnALine.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-04-2017
 *
 * Last Modified : Sat Apr 22 17:55:18 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Hashing double is not a formal way. A formal way should use gcd
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            unordered_map<long double, int> mp;
            int copy = 1;
            for(int j=i+1; j<n; j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y) copy++;
                else if(points[i].x == points[j].x) mp[INT_MAX]++;
                else {
                    long double slope = (long double)(points[i].y - points[j].y)/(long double)(points[i].x - points[j].x);
                    mp[slope]++;
                }
            }
            
            int localMax = 0;
            for(auto& item:mp) localMax= max(localMax, item.second);
            res = max(res, localMax + copy);
        }
        
        return res;
    }
};
