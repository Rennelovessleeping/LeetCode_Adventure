/**************************************************************************
 * File Name : 390-EliminationGame.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-05-2017
 *
 * Last Modified : Mon May  1 15:29:15 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2 * (1 + n/2 -lastRemaining(n/2)); // return mirror image
    }
};
