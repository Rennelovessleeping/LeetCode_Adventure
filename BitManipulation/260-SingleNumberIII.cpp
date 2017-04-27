/**************************************************************************
 * File Name : 260-SingleNumberIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-04-2017
 *
 * Last Modified : Wed Apr 26 22:19:38 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Two pass solution
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        
        vector<int> res(2, 0);
        for(const auto& num:nums) {
            if(num & diff) res[0] ^= num;
            else res[1] ^= num;
        }
        
        return res;
    }
};
