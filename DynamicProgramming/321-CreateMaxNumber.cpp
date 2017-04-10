/**************************************************************************
 * File Name : 321-CreateMaxNumber.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-04-2017
 *
 * Last Modified : Sun Apr  9 21:17:27 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k,0);
        for(int i = max(0, k-n); i<=m && i<=k; i++) {
            vector<int> candidate = merge(maxArray(nums1, i), maxArray(nums2, k-i), k);
            if(greater(candidate, 0, res, 0)) res = candidate;
        }
        return res;
    }

private:
    
    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2, int k) {
        vector<int> res(k);
        for(int i=0, j=0, pos=0; pos<k; pos++) {
            res[pos] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return res;
    }
    
    bool greater(const vector<int>& nums1, int i, const vector<int>& nums2, int j) { // if nums1[i:] > nums2[j:];
        while(i<nums1.size() && j<nums2.size() && nums1[i] == nums2[j]) {
            i++;
            j++;
        }
        
        return j == nums2.size() || (i<nums1.size() && nums1[i] > nums2[j]);
    }
    
    vector<int> maxArray(const vector<int>& nums, int k) { // max number array with length k (greedy)
        int n = nums.size();
        vector<int> res(k);
        for(int i=0, j=0; i<n; i++) {
            while(n-i > k-j && j>0 && res[j-1] < nums[i]) j--; // put the largest digit in the leftmost position
            if(j < k) res[j++] = nums[i];
        }
        return res;
    }
    
};
