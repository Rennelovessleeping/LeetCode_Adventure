/**************************************************************************
 * File Name : 220-ContainDuplicatesIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-03-2017
 *
 * Last Modified : Wed Mar 29 19:46:23 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Use set<long> to maintain a balanced BST
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // Maintan a BST through set;
        set<long> window;
        for(int i=0; i<nums.size(); i++){
            if(i>k) window.erase(nums[i-k-1]);
            // |nums[i] - x| <= t  <-->  nums[i] - t <= x <= t + nums[i];
            auto pos = window.lower_bound((long)nums[i] - t);
            if(pos != window.end() && *pos <= t + (long)nums[i]) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
