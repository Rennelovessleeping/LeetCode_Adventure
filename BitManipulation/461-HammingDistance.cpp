/**************************************************************************
 * File Name : 461-HammingDistance.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-01-2017
 *
 * Last Modified : Tue Jan 17 14:11:32 2017
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

// Loops over bit with all trailing digits being zeros
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int dist = 0;
        int n = x^y;
        while(n){
            dist++;
            n &= (n-1);
        }
        return dist;
    }
};
