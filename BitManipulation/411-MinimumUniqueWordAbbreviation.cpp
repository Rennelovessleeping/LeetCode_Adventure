/**************************************************************************
 * File Name : 411-MinimumUniqueWordAbbreviation.cpp
 *
 * Purpose :
 *
 * Creation Date : 18-04-2017
 *
 * Last Modified : Tue Apr 18 21:25:22 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// The key idea is to abbreviate those comman chars;
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        n = target.size(), bn = 1<<n, flag = 0, minLen = INT_MAX;
        string res;

        // preprocess the words to binary sequence;
        for(const auto& w:dictionary) {
            if(w.size() != n) continue;
            int tmp = 0;
            for(int i=n-1, bit=1; i>=0; i--, bit<<=1) {
                if(w[i] != target[i]) tmp += bit;
            }
            dict.push_back(tmp);
            flag |= tmp;
        }
        
        dfs(1,0);
        
        // Reconstruct abbr from minAbbr
        for(int i=n-1, pre=n-1; i>=0; i--, minAbbr >>= 1) {
            if(minAbbr & 1) { // keep the different char in res
                if(pre -i > 0) res = to_string(pre-i) + res;
                pre = i-1;
                res = target[i] + res;
            }
            else if(i==0) res = to_string(pre-i+1) + res;
        }
        
        return res;
    }
    
    vector<int> dict;
    int n, bn, flag, minLen, minAbbr; // bn is upper bound bit
    
    int abbrLen(int mask) {
        int res = 0;
        for(int bit = 1; bit < bn;){
            if((mask&bit) == 0) { // Repeating element;
                while(bit < bn && (mask & bit) == 0) bit <<= 1;
            }
            else bit <<= 1;
            res++;
        }
        return res;
    }
    
    
    // DFS for searching the mask with shortest abbr
    void dfs(int bit, int mask) {
        //cout << bit << ", " << mask << endl;
        int len = abbrLen(mask);
        
        if(len >= minLen) return;
        bool uniqueAbbr = true;
        
        for(auto w:dict) {
            if((mask & w) == 0) {
                uniqueAbbr = false;
                break;
            }
        }
        
        if(uniqueAbbr) {
            minLen = len;
            minAbbr = mask;
        }
        else{
            for(int b = bit; b < bn; b <<= 1){
                if(flag & b) dfs(b << 1, mask+b);
            }
        }
    }
};
