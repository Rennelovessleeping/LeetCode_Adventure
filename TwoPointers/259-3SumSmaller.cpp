/**************************************************************************
 * File Name : 259-3SumSmaller.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-02-2017
 *
 * Last Modified : Sat Feb 18 20:22:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Two pointer O(N^2) solution
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        
        // Remeber that we just need the total number of triplets!!!
        // Since the uniqueness is gauranteed by indexes, no worry about duplicates!!!
        int res = 0;
        if(nums.empty()) return res;
        sort(nums.begin(), nums.end());

        for(int i=0; i<static_cast<int>(nums.size())-2; ++i){
            int j = i+1, k = nums.size()-1;
            while(j<k){
                if(nums[i] + nums[j] + nums[k] < target) {
                    res += k-j; // Not res++!!
                    j++;
                }
                else k--;
            }
            
        }
        
        return res;
    }
};
