/**************************************************************************
 * File Name : 238-TheSkylineProblem.cpp
 *
 * Purpose :
 *
 * Creation Date : 14-02-2017
 *
 * Last Modified : Tue Feb 14 18:27:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// O(NlogN) solution using heaps 
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>> pq; // {Height, Right Coordinate}; 
        
        int cur = 0, curLoc, curHeight = -1, len = buildings.size();
        
        while(cur<len || !pq.empty()){
            
            curLoc = pq.empty() ? buildings[cur][0] : pq.top().second;
            
            if(cur>=len || curLoc < buildings[cur][0]){ // After scan the left of all the buildings or find the current building
            // start after the previous talles building ends;
                while(!pq.empty() && pq.top().second <= curLoc) pq.pop();
            }
            else{
                // It's possible that previous if fails because the tallest building so far does not end before cur'th building
                curLoc = buildings[cur][0];
                while(cur<len && buildings[cur][0] == curLoc){ // Its possible that multiple buldings share the same left
                    pq.push({buildings[cur][2], buildings[cur][1]}); 
                    cur++;
                }

            }
            
            curHeight = pq.empty() ? 0 : pq.top().first;
            if(res.empty() || res.back().second != curHeight) res.push_back({curLoc, curHeight});
        }
        
        return res;
    }
};

