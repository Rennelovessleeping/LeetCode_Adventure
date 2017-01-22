/**************************************************************************
 * File Name : 278-FindBadVersion.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-01-2017
 *
 * Last Modified : Sat Jan 21 20:21:12 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 1, j = n;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(isBadVersion(mid)) j = mid-1;
            else i = mid+1;
            
        }
        return i;
    }
};
