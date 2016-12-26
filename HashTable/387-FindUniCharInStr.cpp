/**************************************************************************
 * File Name : 387-FindUniCharInStr.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-12-2016
 *
 * Last Modified : Mon Dec 26 00:31:57 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Using maps
class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, pair<int,int>> sDict;
        int firstUniIdx = s.size();
        int len = s.size();
        
        for(int i=0;i<len;i++){
                sDict[s[i]].first++;
                sDict[s[i]].second = i;
        }
        
        for(auto const& a:sDict){
            if (a.second.first==1) firstUniIdx = min(a.second.second, firstUniIdx);
        } 
        return firstUniIdx == s.size() ? -1 : firstUniIdx;
    }
};

// Build alphabet list
class Solution {
public:
    int firstUniqChar(string s) {

        
        int alphabetCount[26] = {0};
        int strLen = s.size();
        int i;
        for(i=0;i<strLen;i++) alphabetCount[s[i]-'a']++;
        for(i=0;i<strLen && alphabetCount[s[i]-'a']>1;i++) {}
        
        return  i==s.size() ? -1:i;
    }
};

