/**************************************************************************
 * File Name : 187-RepeatedDNASequence.cpp
 *
 * Purpose :
 *
 * Creation Date : 19-03-2017
 *
 * Last Modified : Sun Mar 19 21:19:53 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) { 
        vector<string> res;
        if(s.size() < 10) return res;
        unordered_map<int, int> mp;
        unordered_map<int, int> wordCnt;
        mp['A'-'A'] = 0; //00
        mp['C'-'A'] = 1; //01
        mp['G'-'A'] = 2; //10
        mp['T'-'A'] = 3; //11
        // 2 bits for one base pair --> 2*10 = 20bits in total < int 
        
        
        int n = s.size();
        for(int i=0; i+10<=n; i++){
            int tmp = 0;
            for(int j=i; j<i+10; j++){
                tmp <<= 2;
                tmp |= mp[s[j]-'A'];
            }
            wordCnt[tmp]++;
            if(wordCnt[tmp] == 2) res.push_back(s.substr(i, 10));
        }
        
        return res;
        
    }
};
