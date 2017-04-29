/**************************************************************************
 * File Name : 370-RangeAddition.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 11:49:26 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(N*k) solution is trivial
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        
        for(const auto& update:updates) {
            int start = update[0], end = update[1], incr = update[2];
            res[start] += incr;
            if(end + 1 < length) res[end+1] -= incr;
        }
        
        for(int i=1; i<length; i++) {
            res[i] += res[i-1];
        }
        return res;
    }
};
