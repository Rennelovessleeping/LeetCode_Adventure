/**************************************************************************
 * File Name : 451-SortCharactersByFrequency.cpp
 *
 * Purpose :
 *
 * Creation Date : 27-01-2017
 *
 * Last Modified : Fri Jan 27 17:29:39 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char, int> sMap;
        for(int i;i<s.size();i++){
            sMap[s[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto x:sMap){
            pq.push(make_pair(x.second, x.first));
        }
        
        while(!pq.empty()){
            res += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return res;
        
    }
};
