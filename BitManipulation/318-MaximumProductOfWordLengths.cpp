/**************************************************************************
 * File Name : 318-MaximumProductOfWordLengths.cpp
 *
 * Purpose :
 *
 * Creation Date : 29-04-2017
 *
 * Last Modified : Sat Apr 29 00:14:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), res = 0;
        vector<int> mask(n, 0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++) mask[i] |= (1 << (words[i][j] - 'a'));
        }
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++){
                if((mask[i] & mask[j]) == 0) res = max(res, (int)(words[i].length() * words[j].length()));
            }
        }
        
        return res;
    }
};
