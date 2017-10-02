/**************************************************************************
 * File Name : 670-MaximumSwap.cpp
 *
 * Purpose :
 *
 * Creation Date : 25-09-2017
 *
 * Last Modified : Mon Sep 25 12:09:31 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maximumSwap(int num) {
        string res = to_string(num);
        vector<int> bigger(res.size(), -1); // storing the idx of bigger number to right of res[i]
        int n = res.size();
        for(int i=n-1, tmp=n-1; i>=0; i--) {
            if(res[i] > res[tmp]) tmp = i;
            bigger[i] = tmp;
        }
        
        for(int i=0; i<res.size(); i++) {
            if(res[i] != res[bigger[i]]) {
                swap(res[i], res[bigger[i]]);
                break;
            }
        }
        return stoi(res);
    }
};
