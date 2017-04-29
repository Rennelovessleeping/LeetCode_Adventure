/**************************************************************************
 * File Name : 421-MaximumXORofTwoNumbersInAnArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-04-2017
 *
 * Last Modified : Fri Apr 28 21:52:11 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for(int i=31; i>=0; i--){ // determine the res bit by bit from the most significant bit
            mask |= (1<<i);
            unordered_set<int> prefix;
            for(const auto& num:nums) prefix.insert(num & mask); // reserver left bits, cur the candidate pairs are those differ the most in left bits
            
            int tmp = res | (1 << i); // set i'th bit;
            for(const auto& pre:prefix) {
                if(prefix.find(tmp ^ pre) != prefix.end()) { 
					// check wether there is a pair among previously candidates filtered by res that differs on i'th bit 
                    // If so, keep the i'th bit of res as one by res = tmp
                    // else the i'th bit of res should be 0
                    res = tmp;
                    break;
                }
            }
        }
        
        return res;
    }
};
