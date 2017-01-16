/**************************************************************************
 * File Name : 461-HammingDistance.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-01-2017
 *
 * Last Modified : Mon Jan 16 14:32:05 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<8*sizeof(int)> dist(x^y);
        return dist.count();
    }
};
