/**************************************************************************
 * File Name : 88-MergeSortedArray.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-12-2016
 *
 * Last Modified : Thu Feb 23 22:48:01 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Note the difference between in place merge sort and merge sort with allowed extra space.
// When all m elements of num1 has been merged, one only needs to push the remaining elements in nums2 in;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=m-1, j=n-1, backend = m+n-1;
        while(j>=0){
            nums1[backend--] = (i>=0 && nums2[j] < nums1[i]) ? nums1[i--] : nums2[j--];
            
        }
        
        return;
    }

};
