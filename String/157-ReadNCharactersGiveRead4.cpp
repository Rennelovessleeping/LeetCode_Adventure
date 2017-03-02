/**************************************************************************
 * File Name : 157-ReadNCharactersGiveRead4.cpp
 *
 * Purpose :
 *
 * Creation Date : 01-03-2017
 *
 * Last Modified : Wed Mar  1 13:00:46 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Recursive solution
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int shift = min(n, read4(buf));
        if(shift < 4) return shift;
        buf += 4;
        n -=4;
        return 4 + read(buf, n); 
    }
};


