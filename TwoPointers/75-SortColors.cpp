/**************************************************************************
 * File Name : 75-SortColors.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-12-2016
 *
 * Last Modified : Tue Dec 27 14:40:28 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int len = nums.size();
        int first=0, last=len-1;
        for(int i=0;i<len;i++){
            
            while(nums[i]==2 && i<last ) swap(nums[i], nums[last--]);
            while(nums[i]==0 && i>first ) swap(nums[i], nums[first++]);
        }
        
    }
};
