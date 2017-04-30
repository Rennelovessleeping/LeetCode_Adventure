/**************************************************************************
 * File Name : 481-MagicString.cpp
 *
 * Purpose :
 *
 * Creation Date : 30-04-2017
 *
 * Last Modified : Sun Apr 30 12:08:49 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int magicalString(int n) {
        string res = "122";
        int i=2;
        while(res.size()<n) {
            res += string(res[i++]-'0', ((res.back()-'0') ^ 3) + '0');
        }
        
        return count(res.begin(), res.begin()+n, '1');
    }
};
