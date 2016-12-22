/**************************************************************************
 * File Name : 349-IntersectionOfTwoArrays.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-12-2016
 *
 * Last Modified : Wed Dec 21 21:23:17 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Using set intersection directly.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s1( nums1.begin(), nums1.end() );
        set<int> s2( nums2.begin(), nums2.end() );
        
        std::vector<int> uniElem;
        
        std::set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),
                  std::inserter(uniElem,uniElem.begin()));
        
        return uniElem;
    }
};

