/**************************************************************************
 * File Name : 158-ReadNCharactersII.cpp
 *
 * Purpose :
 *
 * Creation Date : 12-02-2017
 *
 * Last Modified : Sun Feb 12 12:43:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
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
        int i = 0;
        while( i<n && ((i4<n4) || (i4=0) < (n4=read4(buf4))) )
            buf[i++] = buf4[i4++];
        return i;
    }
private:
    char buf4[4]; // store the buffer read using read4;
    int i4=0, n4=0; // keep using up the buffer temporarily stored last time;
};
