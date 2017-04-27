/**************************************************************************
 * File Name : 291-WordPatternII.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-04-2017
 *
 * Last Modified : Wed Apr 26 23:14:38 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    unordered_map<char, string> pDict; // mapping : char -> word
    unordered_map<string, char> sDict; // mapping : substr -> char
    bool wordPatternMatch(string pattern, string str) {
        return dfs(pattern,0,str,0);
    }
    
    bool dfs(const string& pattern, int i, const string& str, int pos) {
        int pattern_len = pattern.size();
        int str_len = str.length();
        bool ins = false;
        if(i == pattern_len || pos == str_len){
            if(i == pattern_len && pos == str_len) return true;
            else return false;
        }
        
        for(int j=pos; j<str_len; j++) {
            string tmp = str.substr(pos, j-pos+1);
            if(pDict.find(pattern[i]) != pDict.end()){
                if (pDict[pattern[i]] != tmp) continue;
            } 
            else if(sDict.find(tmp) != sDict.end()){
                if (sDict[tmp] != pattern[i]) continue;
            } 
            else {
                pDict[pattern[i]] = tmp;
                sDict[tmp] = pattern[i];
                ins = true;
            }
            
            if(dfs(pattern, i+1, str, j+1)) return true;
            if(ins) {
                pDict.erase(pattern[i]);
                sDict.erase(tmp);
            }
        }
        
        
        return false;
    }
};
