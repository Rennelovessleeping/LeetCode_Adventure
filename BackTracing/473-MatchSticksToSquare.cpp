/**************************************************************************
 * File Name : 473-MatchSticksToSquare.cpp
 *
 * Purpose :
 *
 * Creation Date : 03-02-2017
 *
 * Last Modified : Fri Feb  3 15:44:50 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Backtracing solution + DP optimization
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if ( nums.size()<4 ) return false;
        int totLength = accumulate(nums.begin(), nums.end(), 0);
        if ( totLength%4 != 0) return false;
        maxLength = totLength/4;
        
        sort(nums.begin(), nums.end(), [] (int& l, int& r){return l > r;}); // descending sort
        vector<int> sideLength(4,0);
        
        return dfs(nums, sideLength, 0, maxLength);
    }

private: 
    int maxLength;
    bool dfs(vector<int>& nums, vector<int>& sideLength, int idx, int& maxLength){
        if(idx == nums.size()) {
            return sideLength[0]==sideLength[1] && sideLength[1]==sideLength[2] && sideLength[2]==sideLength[3];
        }
        
        for(int i=0;i<4;i++){
            if(sideLength[i]+nums[idx] > maxLength) continue;
            
            int j=i;
            while(--j>=0) {
                if(sideLength[j] == sideLength[i]) break; // The same state has been checked
            }
            if(j!=-1) continue; 
            
            sideLength[i] += nums[idx];
            if(dfs(nums, sideLength, idx+1, maxLength)) return true;
            sideLength[i] -= nums[idx];
        }
        
        return false;
    }
    
};

