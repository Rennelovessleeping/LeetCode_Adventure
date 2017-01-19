/**************************************************************************
 * File Name : 365-WaterAndJugProblem.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-01-2017
 *
 * Last Modified : Wed Jan 18 22:37:11 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y || z<0) return false;
        return z==0 || z%__gcd(x,y) == 0; 
    }
};
