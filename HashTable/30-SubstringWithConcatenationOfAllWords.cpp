/**************************************************************************
 * File Name : 30-SubstringWithConcatenationOfAllWords.cpp
 *
 * Purpose :
 *
 * Creation Date : 21-02-2017
 *
 * Last Modified : Tue Feb 21 19:35:46 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// sliding window + hashtable to do the word count statisitcs
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()==0) return res;
        int wordLen = words[0].size();
        unordered_map<string, int> mp; //{word, count}
        
        for(auto word:words) mp[word]++;
        int counter = words.size();
        int i=0, j=0;
        while(j<s.size()){
            if(mp.find(s.substr(j, wordLen)) == mp.end() ){
                while(j<s.size() && mp.find(s.substr(j, wordLen)) == mp.end() ) j++;
                i=j;
            }
            
            while(j<s.size() && mp.find(s.substr(j, wordLen)) != mp.end() && mp[s.substr(j, wordLen)]>0){
                mp[s.substr(j, wordLen)]--;
                counter--;
                j+= wordLen;
            }
            
            if(counter == 0) res.push_back(i);
            if(j<s.size()){
                while(i<j){
                    mp[s.substr(i, wordLen)]++;
                    counter++;
                    i+= wordLen;
                }
                j -= wordLen;
            }
            
        }
        
        return res;
    }
};
