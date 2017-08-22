/**************************************************************************
 * File Name : 593-ValidSquare.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-08-2017
 *
 * Last Modified : Tue Aug 22 17:54:32 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s({
            calc_dist(p1, p2), calc_dist(p1, p3), calc_dist(p1, p4), calc_dist(p2, p3), calc_dist(p2, p4), calc_dist(p3, p4)
        });
        return s.count(0) == 0 && s.size() == 2;
    }
    int calc_dist(const vector<int>& p1, const vector<int>& p2) {
        return (p1[0]-p2[0]) * (p1[0]-p2[0]) + (p1[1]-p2[1]) * (p1[1]-p2[1]);
    }
};
