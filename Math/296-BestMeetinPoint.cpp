/**************************************************************************
 * File Name : 296-BestMeetinPoint.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-03-2017
 *
 * Last Modified : Mon Mar 13 14:47:12 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        vector<int> rows, cols;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                rows.push_back(i);
                cols.push_back(j);
            }
        }
        
        return minDist1D(rows) + minDist1D(cols);
    }
private:

    int minDist1D(vector<int>& index){
        sort(index.begin(), index.end());
        int i = 0, j = index.size() - 1;
        int res = 0;
        while(i<j) res += index[j--] - index[i++];
        return res;
    }
};
