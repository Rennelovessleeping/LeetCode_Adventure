/**************************************************************************
 * File Name : 524-LongestWordInDictionaryThroughDeleting.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-04-2017
 *
 * Last Modified : Sun Apr 23 19:12:04 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(int i=0; i<d.size(); i++) {
            int j=0, k=0;
            for(; j<s.size() && k <d[i].size(); j++) k += s[j] == d[i][k];
            
            if(k == d[i].size() && (res.size() < d[i].size() || res.size() == d[i].size() && d[i]<res)) res = d[i];
        }
        
        return res;
    }
};
