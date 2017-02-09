/**************************************************************************
 * File Name : 239-SlidingWindowMaximum.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-02-2017
 *
 * Last Modified : Wed Feb  8 23:52:50 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(n) solution
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // Descending double ended queue whose front is always the largest in current window
        
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && i-dq.front() == k) dq.pop_front();// remove  out-of-window maximum;
            while(!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};

