/**************************************************************************
 * File Name : 265-PaintHouseII.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-02-2017
 *
 * Last Modified : Sun Feb 26 13:07:20 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// We only need to memorize the 1st and 2nd smallest cost till previous house
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n==0) return 0;
        int k = costs[0].size();
        
        int min1 = -1, min2 = -1; // the index of colors with smallest and 2nd smallest cost till previous house
        for(int i=0; i<n; i++){
            int last1 = min1, last2 = min2;
            min1 = -1; min2 = -1; // Initialize the indexes for searching
            for(int j=0; j<k; j++){
                // Update costs till (i+1)'the house in place
                if(j!=last1){
                    costs[i][j] += last1 < 0 ? 0 : costs[i-1][last1];
                }
                else{
                    costs[i][j] += last2 < 0 ? 0 : costs[i-1][last2];
                }
                
                // Update the index of 1st and 2nd smallest cost;
                if(min1 < 0 || costs[i][j] < costs[i][min1]){
                    min2 = min1;
                    min1 = j;
                }
                else if(min2 < 0 || costs[i][j] < costs[i][min2]){
                    min2 = j;
                }
            }
        }
        
        return costs[n-1][min1];
    }
};


