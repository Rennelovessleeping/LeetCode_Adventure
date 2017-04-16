/**************************************************************************
 * File Name : 555-SplitAssembledString.cpp
 *
 * Purpose :
 *
 * Creation Date : 16-04-2017
 *
 * Last Modified : Sun Apr 16 14:12:03 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s = "";
        for(int i=0; i<strs.size(); i++) {
            string r = strs[i];
            reverse(r.begin(), r.end());
            s += max(strs[i], r);
        }
        
        string res = "a";
        for(int i=0, start = 0; i<strs.size(); start += strs[i++].size()) {
            string s1 = strs[i], s2 = strs[i];
            reverse(s2.begin(), s2.end());
            for(int j=0; j<strs[i].size(); j++) {
                string r1 = s1[j] >= res[0] ? 
                    s1.substr(j) + s.substr(start + s1.size()) + s.substr(0, start) + s1.substr(0, j) : "";
                string r2 = s2[j] >= res[0] ?  
                    s2.substr(j) + s.substr(start + s2.size()) + s.substr(0, start) + s2.substr(0, j) : "";
                
                res = max(res, max(r1, r2));
            }
        }
        
        return res;
    }
};
