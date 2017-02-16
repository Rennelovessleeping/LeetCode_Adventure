/**************************************************************************
 * File Name : 477-TotalHammingDistance.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-02-2017
 *
 * Last Modified : Thu Feb 16 17:38:40 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(n) solution
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = 8*sizeof(int), sum = 0;
        
        for(int i=0; i<len; ++i){
            int ones = 0, zeros = 0;
            for(int j=0; j<nums.size(); ++j){
                if(nums[j] & 1) ones++;
                else zeros++;
                nums[j] >>= 1;
            }
            sum += zeros*ones;
        }
        return sum;
    }
};

// trivial O(n^2) solution
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size(); ++i){
            for(int j=i+1; j<nums.size(); ++j) sum += HammingDist(nums[i], nums[j]);
        }
        return sum;
    }
private:
    int HammingDist(int& num1, int& num2){
        bitset<8*sizeof(int)> tmp(num1^num2);
        return tmp.count();
    }
};
