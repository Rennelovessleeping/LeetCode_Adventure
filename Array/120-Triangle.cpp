/**************************************************************************
 * File Name : 120-Triangle.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-12-2016
 *
 * Last Modified : Wed Dec 28 12:52:00 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Recursive Formula beyond time limit...
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        /*---- test case ----*/
        //triangle = {{-1},{2,3},{1,-1,-3}};
        //triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
        //triangle = {{-1},{3,2},{-3,1,-1}};
        
        if (triangle.size()==0) return 0;
        return belowSum(0,0,triangle);
        
    }
    
    int belowSum(int i, int j, vector<vector<int>>& triangle){
        
        if (i==triangle.size()-1) return triangle[i][j];
        int left = max(0, j);
        int right = min(j+1,i+1);
        int sum_left = triangle[i][j] + belowSum(i+1, left, triangle);
        int sum_right = triangle[i][j] + belowSum(i+1, right, triangle);
        
        return min(sum_left < sum_right);        
    }
};

// Dynamic programming
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int layer = triangle.size();
        if (layer==0) return 0;
        
        vector<int> minSum = triangle[layer-1];
        
        for(int i=layer-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                minSum[j] = triangle[i][j] + min(minSum[j], minSum[j+1]);
            }
        }
        
        return minSum[0];
        
    }
    
};
