/**************************************************************************
 * File Name : 502-IPO.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-04-2017
 *
 * Last Modified : Fri Apr 14 18:57:15 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        
        priority_queue<int> doable; // max_heap stores the most profitable proj with current capital K
        multiset<pair<int, int>> undoable; // {capital: profit}
        
        for(int i=0; i<Profits.size(); i++) {
            if(Profits[i] <= 0) continue;
            if(Capital[i] <= W) doable.push(Profits[i]);
            else undoable.insert({Capital[i], Profits[i]});
        }
        
        while(k-- && !doable.empty()) {
            W += doable.top(); doable.pop();
            for(auto it = undoable.begin(); undoable.size() && it-> <= W; it = undoable.erase(it)) {
                doable.push(it->second);
            }
        }
        
        return W;
    }
};
