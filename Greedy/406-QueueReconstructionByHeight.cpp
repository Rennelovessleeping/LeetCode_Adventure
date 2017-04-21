/**************************************************************************
 * File Name : 406-QueueReconstructionByHeight.cpp
 *
 * Purpose :
 *
 * Creation Date : 20-04-2017
 *
 * Last Modified : Thu Apr 20 21:43:00 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Find the tallest ppl first and sort them by k;
// Find the second tallest ppl and sort them by k too, insert the sorted second tallest among the tallest ones
// same procedure for the remaining ppl
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](pair<int,int>& l, pair<int,int>& r) {
            return l.first > r.first || (l.first == r.first && l.second < r.second);
        };
        
        sort(people.begin(), people.end(), cmp);
        vector<pair<int,int>> res;
        for(auto p:people) {
            res.insert(res.begin() + p.second, p);
        }
        return res;
    }
};
