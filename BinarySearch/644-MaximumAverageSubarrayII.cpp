/**************************************************************************
 * File Name : 644-MaximumAverageSubarrayII.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-08-2017
 *
 * Last Modified : Sat Aug 12 15:16:29 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// use a greedy method to find the candidate subarray that is at least k-size long
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double lo = INT_MIN, hi = INT_MAX;
        while(hi - lo > 0.0000001) {
            double mid = (lo + hi)/2;
            if(isValid(nums, k, mid)) lo = mid;
            else hi = mid;
        }
        
        return hi;
    }
    
    bool isValid(const vector<int>& nums, int k, double avg) { 
        // whether there is a subarray (length >= k) with avareage >= avg
        vector<double> a(nums.size());
        for(int i=0; i<a.size(); i++) a[i] = nums[i] - avg;
        
        double cursum = 0, presum = 0;
        for(int i=0; i<k; i++) cursum += a[i];
        if(cursum >= 0) return true;
        for(int i=k; i<a.size(); i++) { // the size of sliding window is at least k
            cursum += a[i];
            presum += a[i-k];
            if(presum <= 0) {
                cursum -= presum;
                presum = 0;
            }
            
            if(cursum >= 0) return true;
        }
        
        return false;
    }
};
