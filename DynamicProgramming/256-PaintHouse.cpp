/**************************************************************************
 * File Name : 256-PaintHouse.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-02-2017
 *
 * Last Modified : Sun Feb 26 12:06:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DP solution with space optimization
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> pre(3,0);
        for(int i=0; i<costs.size(); i++){
            vector<int> cur(3,0);
            cur[0] = min(pre[1], pre[2]) + costs[i][0];
            cur[1] = min(pre[0], pre[2]) + costs[i][1];
            cur[2] = min(pre[0], pre[1]) + costs[i][2];
            pre.swap(cur);
        }
        
        return min(pre[0], min(pre[1], pre[2]));
    }
};
