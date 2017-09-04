/**************************************************************************
 * File Name : 658-FindKClosestElements.cpp
 *
 * Purpose :
 *
 * Creation Date : 03-09-2017
 *
 * Last Modified : Sun Sep  3 21:18:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int i= idx-1, j = idx;
        while(k-- > 0) {
            if(i<0 || (j<arr.size() && abs(arr[i]-x) > abs(arr[j]-x)) ) j++;
            else i--;
        }
        return vector<int> (arr.begin()+i+1, arr.begin()+j);
    }
};
