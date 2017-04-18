/**************************************************************************
 * File Name : 527-WordAbbreviation.cpp
 *
 * Purpose :
 *
 * Creation Date : 17-04-2017
 *
 * Last Modified : Mon Apr 17 20:29:19 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int len = dict.size();
        vector<string> res(len);
        vector<int> prefix(len, 1); // length of prefix;
        
        for(int i=0; i<len; i++) res[i] = makeAbbr(dict[i], prefix[i]);
        
        for(int i=0; i<len; i++) {
            while(true) {
                unordered_set<int> set;
                for(int j=i+1; j<len; j++) {
                    if(res[i] == res[j]) set.insert(j);
                }
                
                if(set.empty()) break;
                set.insert(i);
                for(int j:set) res[j] = makeAbbr(dict[j], ++prefix[j]);
            }
            
        }
        
        return res;
    }
    
    string makeAbbr(const string& s, int k) { // k - prefix length
        int len = s.size();
        if(k+2 >= len) return s;
        return s.substr(0,k) + to_string(len-k-1) + s.substr(len-1);
    }
};
