/**************************************************************************
 * File Name : 220-ContainDuplicatesIII.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-03-2017
 *
 * Last Modified : Wed Mar 29 21:48:26 2017
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

// O(N) solution use bucketing treaks that maps a range to a key value;
// Then a range query becomes O(1) operation
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k < 1 || t < 0) return false;
        // use bucketing to map a range to a number; 
        unordered_map<long, long> mp;
        for(int i=0; i<nums.size(); i++){
            long remappedNum = (long) nums[i] - INT_MIN;
            long bucket = remappedNum / ((long)t + 1);
            if(mp.find(bucket) != mp.end() || (mp.find(bucket-1) != mp.end() && remappedNum - mp[bucket-1]<=t) ||
                (mp.find(bucket+1) !=  mp.end() && mp[bucket+1] - remappedNum <=t)) return true;
            if(mp.size() >= k) {
                long tmp =  ((long) nums[i-k] - INT_MIN) / ((long)t + 1);
                mp.erase(tmp);
            }
            mp[bucket] = remappedNum;
        }
        
        return false;
    }
};

