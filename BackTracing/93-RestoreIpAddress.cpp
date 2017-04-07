/**************************************************************************
 * File Name : 93-RestoreIpAddress.cpp
 *
 * Purpose :
 *
 * Creation Date : 06-04-2017
 *
 * Last Modified : Thu Apr  6 19:41:48 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// DFS
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restoreIpAddress(s, res, "", 0, 0);
        return res;
    }
    
    void restoreIpAddress(const string& s, vector<string>& res, string path, int idx, int count) {
        // count -- valid # of blocks;
        if(count > 4) return;
        if(count == 4 && idx == s.length()) {
            res.push_back(path);
            return;
        }

        for(int len=1; len<=3; len++) {
            if(idx + len > s.length()) break;
            string tmp = s.substr(idx, len);
            if((tmp[0] == '0' && tmp.length() > 1) || (tmp.length() == 3 && stoi(tmp) > 255) ) break;
            restoreIpAddress(s, res, path + tmp + (count == 3 ? "" : "."), idx+len, count+1);
        }
    }
};
