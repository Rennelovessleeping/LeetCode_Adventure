/**************************************************************************
 * File Name : 466-CountTheRepetitions.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-04-2017
 *
 * Last Modified : Thu Apr 27 22:24:28 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCnt(s2.size()+1, 0); // When exhausting s2, there must be a repeating pattern
        vector<int> nextStartIdx(s2.size()+1, 0); // use n1+1 waste a lot mem

        int j=0, cnt=0;
        for(int k=1; k<=n1; k++){
            for(int i=0; i<s1.size(); i++) {
                if(s1[i] == s2[j]) j++;
                if(j == s2.size()) {
                    cnt++;
                    j = 0;
                }
            }
            
            repeatCnt[k] = cnt; // If we stop here and dont check the possible repetitive pattern, we'll get tle;
            nextStartIdx[k] = j;
            
            for(int start=0; start < k; start++) {
                if(nextStartIdx[start] == j) {
                    int prefixCnt = repeatCnt[start]; // repeat cnt in first start s1 segments
                    int patternCnt = (repeatCnt[k] - repeatCnt[start])*(n1-start)/(k-start); // full pattern cnt
                    int suffixCnt = repeatCnt[start + (n1-start)%(k-start)] - repeatCnt[start];
                    
                    return (prefixCnt + patternCnt + suffixCnt) / n2;
                }
            }
            
        }
        
        return repeatCnt[n1] / n2;
    }
};
