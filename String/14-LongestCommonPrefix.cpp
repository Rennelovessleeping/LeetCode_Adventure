/**************************************************************************
 * File Name : 14-LongestCommonPrefix.cpp
 *
 * Purpose :
 *
 * Creation Date : 02-01-2017
 *
 * Last Modified : Mon Jan  2 11:34:50 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0) return "";
        
        string prefix;
        int len=INT_MAX;
        int i,j;
        for(int i=0;i<strs.size();i++){ // search the shortest string
            len = strs[i].size() < len ? strs[i].size() : len;
        }
        
        for(i=0;i<len;i++){
            for(j=1;j<strs.size();j++){
                if (strs[j][i] != strs[j-1][i]) return prefix;
            }
            prefix.push_back(strs[j-1][i]);
        }
        
        return prefix;
        
    }
};

// Refined Solution
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix;
        
        int len=INT_MAX;
        int i,j;
        
        for(i=0;strs.size()>0;i++){
            for(j=0;j<strs.size();j++){
                if (i>= strs[j].size() || (j>0 && strs[j][i] != strs[j-1][i]) ) return prefix;
            }
            prefix.push_back(strs[j-1][i]);
        }
        
        return prefix;
        
    }
};
