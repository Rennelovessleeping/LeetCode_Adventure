/**************************************************************************
 * File Name : 438-FindAllAnagramsInString.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-02-2017
 *
 * Last Modified : Tue Feb  7 21:42:41 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// build hashtable for all 256 characters;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int slen = s.size(), plen = p.size();
        int left = 0, right = 0, count=plen;
        vector<int> res;
        vector<int> pstr((int)pow(2,sizeof(char)*8), 0);
    
        for(int i=0;i<plen;i++) pstr[p[i]]++;
        //for(int i=0;i<pstr.size();i++) cout << pstr[i] << endl;
        
        while(right < slen){
            if( pstr[s[right++]]-- >0) count--;
            if(count==0) res.push_back(left);
            if( (right-left)==plen && pstr[s[left++]]++ >=0) count++;
            
        }
        return res;
    }
};

