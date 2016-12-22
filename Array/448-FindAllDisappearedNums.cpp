/**************************************************************************
 * File Name : 448-FindAllDisappearedNums.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-12-2016
 *
 * Last Modified : Thu Dec 22 16:35:27 2016
 *
 * Created By :  
**************************************************************************/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> disappearedNums;
        int len = nums.size();
        int i, mappingIdx;
        
        for(i=0;i<len;i++){
            mappingIdx = abs(nums[i]) - 1;
            nums[mappingIdx] = nums[mappingIdx] > 0 ? -nums[mappingIdx]:nums[mappingIdx];
        }
        
        for(i=0;i<len;i++){
            if(nums[i]>0) disappearedNums.push_back(i+1);
        }
        
        return disappearedNums;
        
    }
};
