/**************************************************************************
 * File Name : 611-ValidTriangleNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-06-2017
 *
 * Last Modified : Fri Jun 23 15:52:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), res = 0;
        
        for(int k=len-1; k>=2; k--) {
            int i=0, j = k-1;
            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    res += j-i;
                    j--;
                }
                else i++;
            }
        }
        
        return res;
    }
};
