/**************************************************************************
 * File Name : 4-MedianOfTwoSortedArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-03-2017
 *
 * Last Modified : Sun Mar 12 13:41:13 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// The key idea is to use binary search to move the median cut in nums1 and nums2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m<n) return findMedianSortedArrays(nums2, nums1);
        if(n==0) return ((double)nums1[(m-1)/2] + (double)nums1[m/2])/2;
        
        int left = 0, right = 2*n;
        while(left <= right){
            int mid2 = left + (right-left)/2;
            int mid1 = m + n - mid2;
            
            double L1 = mid1==0 ? INT_MIN : nums1[(mid1-1)/2];
            double L2 = mid2==0 ? INT_MIN : nums2[(mid2-1)/2];
            double R1 = mid1==2*m ? INT_MAX : nums1[mid1/2];
            double R2 = mid2==2*n ? INT_MAX : nums2[mid2/2];
            
            if(L2 > R1) right = mid2 - 1;
            else if(L1 > R2) left = mid2 + 1;
            else return (min(R1, R2) + max(L1, L2))/2;
        }
        return -1;
    }
};
