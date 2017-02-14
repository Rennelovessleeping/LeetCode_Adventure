/**************************************************************************
 * File Name : 238-ProductOfArrayExceptSelf.cpp
 *
 * Purpose :
 *
 * Creation Date : 13-02-2017
 *
 * Last Modified : Mon Feb 13 21:49:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(n) time and O(n) space solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fromBegin(nums.size()), fromEnd(nums.size());
        fromBegin[0] = 1;
        fromEnd[0] = 1;
        for(int i=1;i<nums.size();i++){
            fromBegin[i] = fromBegin[i-1]*nums[i-1];
            fromEnd[i] = fromEnd[i-1]*nums[nums.size()-i];
        }
        vector<int> res(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            res[i] = fromBegin[i]*fromEnd[nums.size()-1-i];
        }
        return res;
    }
};

// O(1) Solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int fromBegin = 1, fromEnd = 1;
        vector<int> res(nums.size(),1);
        
        for(int i=1;i<nums.size();i++){
            fromBegin *= nums[i-1];
            res[i] *= fromBegin;
            fromEnd *= nums[nums.size()-i];
            res[nums.size()-1-i] *= fromEnd;
        }
        
        return res;
    }
};

