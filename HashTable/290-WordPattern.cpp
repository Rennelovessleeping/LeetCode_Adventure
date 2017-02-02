/**************************************************************************
 * File Name : 290-WordPattern.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-02-2017
 *
 * Last Modified : Thu Feb  2 00:09:33 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        vector<string> strs = split(str);
        if(strs.size()!=pattern.length()) return false;
        
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
		// hash function that maps patter[i] and strs[i] to a i/pos-dependent number
        for(int i=0; i<pattern.size();i++){
            if(p2i[pattern[i]] != w2i[strs[i]]) return false;
            p2i[pattern[i]] = w2i[strs[i]] = i+1;
        }
        
        return true;
    }
    
private:
    vector<string> split(string& str){
        vector<string> ans;
        int len = str.length();
        int i=0,j=0;
        for(;i<len;i++){
            if(str[i] == ' ') {
                ans.push_back(str.substr(j,i-j));
                j = i + 1;
            }
        } 
        ans.push_back(str.substr(j,i-j));
        return ans; 
    }

};

// use istringstream;
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        istringstream ss(str);
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        int i = 0, len = pattern.length();
        
        for(string w; ss>>w ;i++){
            // i+1 is the word number;
            if( i==len || p2i[pattern[i]] != w2i[w]) return false;
            p2i[pattern[i]] = w2i[w] = i+1;
        }
        
        return i==len;
    }
    

};
