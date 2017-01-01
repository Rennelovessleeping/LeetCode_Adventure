/**************************************************************************
 * File Name : 303-RangeSumQueryImmutable.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-01-2017
 *
 * Last Modified : Sun Jan  1 12:46:53 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class NumArray {
public:
    NumArray(vector<int> &nums) : accumSum(nums.size()+1, 0) {
        partial_sum(nums.begin(), nums.end(), accumSum.begin()+1);
    }

    int sumRange(int i, int j) {
        return accumSum[j+1] - accumSum[i];
    }
private:
    vector<int> accumSum;
    
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
