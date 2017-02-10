/**************************************************************************
 * File Name : 277-FindCelebrity.cpp
 *
 * Purpose :
 *
 * Creation Date : 09-02-2017
 *
 * Last Modified : Thu Feb  9 22:44:15 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) { 
        
        int celebrity = 0;
        for(int i=1;i<n;i++) {
            if(knows(celebrity, i)) celebrity = i;
        }
        
        for(int i=0;i<n;i++){
            if (i==celebrity) continue;
            if (knows(celebrity, i) || !knows(i, celebrity)) return -1;
        }
        
        return celebrity;
    }
};
