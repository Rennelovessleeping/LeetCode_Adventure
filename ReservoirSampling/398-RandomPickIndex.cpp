/**************************************************************************
 * File Name : 398-RandomPickIndex.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-02-2017
 *
 * Last Modified : Tue Feb 14 22:15:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Reservoir Sampling
class Solution {
public:
    vector<int> n;
    Solution(vector<int> nums) {
        n = nums;
    }
    
    int pick(int target) {
        int res = -1; // return -1 if the target doesnt exist
        int count = 0;
        for(int i=0;i<n.size();i++){
            if (n[i] != target) continue;
            
            if (++count == 1) res = i; // keep the first
            else if((rand()%count)==0) res = i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
