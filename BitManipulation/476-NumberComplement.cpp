/**************************************************************************
 * File Name : 476-NumberComplement.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-04-2017
 *
 * Last Modified : Fri Apr 28 20:50:32 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        // cout << bitset<32>(mask) << endl;
        while(num & mask) mask <<= 1;
        
        return ~num & ~mask;
    }
};
