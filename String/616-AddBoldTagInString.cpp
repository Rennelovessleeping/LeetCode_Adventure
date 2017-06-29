/**************************************************************************
 * File Name : 616-AddBoldTagInString.cpp
 *
 * Purpose :
 *
 * Creation Date : 28-06-2017
 *
 * Last Modified : Wed Jun 28 13:33:46 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        
        // Solution using the idea of merge interval
        vector<pair<int, int>> intervals;
        for(string word:dict){
            for(int i=0; (i=s.find(word, i)) != string::npos; i++) {
                intervals.push_back({i, i+word.length()});
                // cout << intervals.back().first << ", " << intervals.back().second << endl;
            }
        }
        
        vector<pair<int,int>> tmp = mergeIntervals(intervals);
        // Insert bold tags from end to start
        for(auto rit = tmp.rbegin(); rit!=tmp.rend(); rit++){
            //cout << rit->first << ", " << rit->second << endl;
            s.insert(rit->second, "</b>");
            s.insert(rit->first, "<b>");
        }
        
        return s;
    }
    
    vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> intervals) {
        vector<pair<int, int>> res;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++) {
            if (res.empty() || intervals[i].first > res.back().second) res.push_back(intervals[i]);
            else res.back().second = max(res.back().second, intervals[i].second);
        }
        return res;
    }
    
    //static bool cmp(const pair<int, int>& l, const pair<int, int>& r) {return l.first < r.first;}
};
