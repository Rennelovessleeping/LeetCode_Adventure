/**************************************************************************
 * File Name : 345-ReverseVowelsOfString.cpp
 *
 * Purpose :
 *
 * Creation Date : 26-12-2016
 *
 * Last Modified : Mon Dec 26 14:18:12 2016
 *
 * Created By :  Renne Bai
**************************************************************************/
// Naive swap
class Solution {
public:
    string reverseVowels(string s) {
        
        vector<int> vowelIdx;
        for(int i=0;i<s.size();i++){
            if (isVowel(s[i])) vowelIdx.push_back(i);
        }
        
        for(int i=0; i<vowelIdx.size()/2;i++) swap( s[vowelIdx[i]], s[vowelIdx[vowelIdx.size()-1-i]] );
        return s;
        
    }
    
    bool isVowel(char c){
        unordered_set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        return vowels.find(c)!=vowels.end();
    }
};

// Standard two ptr method
class Solution {
public:
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            i = s.find_first_of("aeiouAEIOU",i);
            j = s.find_last_of("aeiouAEIOU",j);
            if(i<j) swap(s[i++],s[j--]);
        }
        return s;
    }

};


