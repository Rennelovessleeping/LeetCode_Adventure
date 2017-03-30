/**************************************************************************
 * File Name : 442-FindAllDuplicatesInAnArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-03-2017
 *
 * Last Modified : Wed Mar 29 19:22:00 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// twice --> flipping signs;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0) res.push_back(idx+1);
            nums[idx] = - nums[idx];
        }
        
        return res;
    }
};

