/**************************************************************************
 * File Name : 335-SelfCrossing.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-04-2017
 *
 * Last Modified : Sun Apr 23 14:46:17 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        x.insert(x.begin(), 4, 0);
        
        int len = x.size();
        int i=4;
        
        // Check outer spiral
        for(; i<len && x[i] > x[i-2]; i++);
        if(i == len) return false;
        
        // check border
        if(x[i] >= x[i-2] - x[i-4]) x[i-1] -= x[i-3];
        
        
        // Check innter spiral
        for(i++; i<len && x[i] < x[i-2]; i++);
        
        return i != len;
    }
};
