/**************************************************************************
 * File Name : 229-MajorityVoteII.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-03-2017
 *
 * Last Modified : Thu Mar  9 21:54:45 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Boyer-Moore algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n==0) return nums;
        
        int idx1 = 0, idx2 = 1, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == nums[idx1]) cnt1++;
            else if(nums[i] == nums[idx2]) cnt2++;
            else if(cnt1 == 0) {
                idx1 = i;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                idx2 = i;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        // dont use count for nums[idx1] and nums[idx2] seperately, cuz they could be the same
        cnt1 = cnt2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == nums[idx1]) cnt1++;
            else if(nums[i] == nums[idx2]) cnt2++;
        }
        
        if(cnt1 > n/3) res.push_back(nums[idx1]);
        if(cnt2 > n/3) res.push_back(nums[idx2]);
        
        return res;
        
    }
};
