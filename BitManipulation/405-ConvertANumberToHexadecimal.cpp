/**************************************************************************
 * File Name : 405-ConvertANumberToHexadecimal.cpp
 *
 * Purpose :
 *
 * Creation Date : 15-04-2017
 *
 * Last Modified : Sat Apr 15 17:54:02 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    const string HEX = "0123456789abcdef";
    string toHex(int num) {
        if(num == 0) return "0";
        
        string res = "";
        int i = 0;
        while (num && i++ < 8){ // no leading zeros
            res = HEX[num & 0xf] + res;
            num >>= 4;
        }
        
        return res;
    }
};
