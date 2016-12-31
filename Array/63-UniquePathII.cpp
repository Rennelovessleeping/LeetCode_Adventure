/**************************************************************************
 * File Name : 63-UniquePathII.cpp
 *
 * Purpose :
 *
 * Creation Date : 31-12-2016
 *
 * Last Modified : Sat Dec 31 15:49:49 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// raw-DP
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> pathNum(rows, vector<int>(cols,0));
        int i=0,j=0;
        
        while(i<rows && !obstacleGrid[i][0]) { pathNum[i][0] = 1; i++;}
        while(j<cols && !obstacleGrid[0][j]) { pathNum[0][j] = 1; j++;}
        
        
        for(i=1;i<rows;i++){
            for(j=1;j<cols;j++){
                if (obstacleGrid[i][j]) pathNum[i][j] = 0;
                else pathNum[i][j] = pathNum[i-1][j] + pathNum[i][j-1];
            }
        }
        return pathNum[rows-1][cols-1];
        
    }
};

// Due to the obstacles, space optimization is not feasible. 
