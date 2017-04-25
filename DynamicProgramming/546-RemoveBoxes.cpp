/**************************************************************************
 * File Name : 546-RemoveBoxes.cpp
 *
 * Purpose :
 *
 * Creation Date : 24-04-2017
 *
 * Last Modified : Mon Apr 24 23:13:37 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {0};
        // dp[i][j][k] -- k boxes append to boxes[i]...box[j], where k boxes' color are the same as boxes[j]
        return dfs(boxes, dp, 0, n-1, 0);
    }
    
    int dfs(vector<int>& boxes, int dp[100][100][100], int l, int r, int k) {
        if(l > r) return 0;
        if(dp[l][r][k]) return dp[l][r][k];
        
        while(r>l && boxes[r] == boxes[r-1]) r--, k++;
        dp[l][r][k] = dfs(boxes, dp, l, r-1,0) + (k+1)*(k+1); // merge the k+1 boxes
        for(int i=l; i<r; i++) {
            if(boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k], dfs(boxes, dp, i+1, r-1, 0) + dfs(boxes, dp, l, i, k+1));
            }
        }
        
        return dp[l][r][k];
    }
};
