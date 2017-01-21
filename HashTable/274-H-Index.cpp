/**************************************************************************
 * File Name : 274-H-Index.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-01-2017
 *
 * Last Modified : Fri Jan 20 16:43:16 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        if(citations.size()==0) return 0;
        int len = citations.size();
        int hash_table[len+1] = {0};
        
        for(int i=0;i<len;i++){ // last item of hash_table is ther sum of paper cited at least len times;
            if(citations[i]>len) hash_table[len]++;
            else hash_table[citations[i]]++;
        }
        
        int tot_paper=0;
        for(int i=len;i>=0;i--){
            tot_paper += hash_table[i];
            if(tot_paper>=i) return i;
        }
    }
};
