/**************************************************************************
 * File Name : 89-GrayCode.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-04-2017
 *
 * Last Modified : Wed Apr 26 23:35:09 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<int> grayCode(int n) {
        int N = 1<<n;
        vector<int> res;
        for(int i=0; i<N; i++) {
            res.push_back(i ^ (i>>1));
        }
        
        return res;
    }
};
