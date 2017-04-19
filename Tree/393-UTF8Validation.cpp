/**************************************************************************
 * File Name : 393-UTF8Validation.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-04-2017
 *
 * Last Modified : Tue Apr 18 20:13:14 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for(int num:data) {
            if(cnt == 0) {
                if((num >> 5) == 0b110) cnt =1;
                else if((num >> 4) == 0b1110) cnt = 2;
                else if((num >> 3) == 0b11110) cnt = 3;
                else if((num >> 7)) return false;
            }
            else {
                if ((num >> 6) != 0b10) return false;
                cnt--;
            }
        }
        
        return cnt == 0;
    }
};
