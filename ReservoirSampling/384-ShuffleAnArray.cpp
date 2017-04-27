/**************************************************************************
 * File Name : 384-ShuffleAnArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-04-2017
 *
 * Last Modified : Tue Apr 25 22:47:41 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> nums, copy;
    Solution(vector<int> nums) {
        srand(time(NULL));
        this->nums = nums;
        copy = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        //nums = copy;
        return copy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=nums.size()-1; i>0; i--){
            int j = rand() % (i+1);
            swap(nums[i], nums[j]);
        }
        return nums;
    }
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
