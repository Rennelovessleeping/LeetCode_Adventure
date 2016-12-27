/**************************************************************************
 * File Name : 350-IntersectionOfTwoArraysII.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-12-2016
 *
 * Last Modified : Mon Dec 26 23:21:00 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //nums1 = {1,3,4,5}; nums2 = {5,6,7};
        
        vector<int> intersectNum;
        /*
        // Brutally iterate twice
        map<int,int> dict;
        for(int i=0;i<nums1.size();i++) dict[nums1[i]]++;
        for(int i=0;i<nums2.size();i++) if(dict[nums2[i]]-- > 0) intersectNum.push_back(nums2[i]);
        */
        
        /*------- sort -------*/
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int len1=nums1.size(), len2=nums2.size();
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(nums1[i]==nums2[j]) {intersectNum.push_back(nums1[i]); i++; j++;}
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        
        return intersectNum;
    }
};
