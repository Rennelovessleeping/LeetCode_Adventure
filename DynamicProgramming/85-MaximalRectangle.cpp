/**************************************************************************
 * File Name : 85-MaximalRectangle.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-02-2017
 *
 * Last Modified : Tue Feb 28 11:25:36 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int  m = matrix.size(), n = m ? matrix[0].size() : 0;
        vector<int> left(n, 0), right(n, n), height(n, 0); // boundaries;
        
        int maxArea = 0;
        for(int i=0; i<m ;i++){
            int curLeft = 0, curRight = n; // Left and right boundaries on current row;
            
            // update the height first
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            
            // update the left boundary for (i,j)'th point
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0; //reset the left boundary for j+1 search ;
                    curLeft = j+1; // left boundary inclusive
                }
            }
            
            // update the right boundary for (i,j)'th point
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j] == '1') right[j] = min(right[j], curRight);
                else{
                    right[j] = n;
                    curRight = j; // right boundary exclusive;
                }
            }
            
            for(int j=0; j<n; j++) maxArea = max(maxArea, (right[j]-left[j])*height[j]);
            
        }
        return maxArea;
    }
};
