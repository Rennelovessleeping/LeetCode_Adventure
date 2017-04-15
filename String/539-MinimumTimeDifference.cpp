/**************************************************************************
 * File Name : 539-MinimumTimeDifference.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-04-2017
 *
 * Last Modified : Sat Apr 15 18:47:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int minDiff = INT_MAX;
        for(int i=0; i<n; i++) {
            int diff = time_diff(timePoints[(i-1+n) % n], timePoints[i]);
            diff = min(diff, 1440 - diff);
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }

private:
    int time_diff(const string& t1, const string& t2) {
        int h1 = stoi(t1.substr(0,2)), m1 = stoi(t1.substr(3));
        int h2 = stoi(t2.substr(0,2)), m2 = stoi(t2.substr(3));
        return abs((h2 - h1) * 60 + m2 - m1);
    }
};
