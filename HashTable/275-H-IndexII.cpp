/**************************************************************************
 * File Name : 275-H-IndexII.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-01-2017
 *
 * Last Modified : Fri Jan 20 18:27:06 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// BST
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int len = citations.size(), left = 0, right = len-1, mid;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            if(citations[mid] == len-mid) return citations[mid];
            if(citations[mid] < len-mid) left = mid+1;
            if(citations[mid] > len-mid) right = mid-1;
        } // The loop always ends up at right = left-1; All element in citations to right of "right" has more citation than citation[right]
        cout << left << ", " << right << endl;
        return len - left;
        
    }
};
