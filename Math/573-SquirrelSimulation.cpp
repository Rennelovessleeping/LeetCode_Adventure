/**************************************************************************
 * File Name : 573-SquirrelSimulation.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-08-2017
 *
 * Last Modified : Sun Aug 27 17:55:33 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Only the first visited nut determines the total dist; for all the remaining nuts, we have to start fromt the tree and then come back to that tree
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int tot_dist = 0, missing_dist = INT_MIN; // maximal missing_dist could be negative: squirrel is far from all nuts and the tree;
        for(const auto& nut:nuts) {
            tot_dist += 2*calc_dist(tree, nut);
            missing_dist = max(missing_dist, calc_dist(tree, nut) - calc_dist(squirrel, nut));
        }
        return tot_dist - missing_dist;
    }
    int calc_dist(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
};
