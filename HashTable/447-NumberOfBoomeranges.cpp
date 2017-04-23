/**************************************************************************
 * File Name : 447-NumberOfBoomeranges.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-04-2017
 *
 * Last Modified : Sat Apr 22 18:14:26 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0, n = points.size();
        
        for(int i=0; i<n; i++){
            unordered_map<int, int> mp;
            for(int j=0; j<n; j++) {
                if(j == i) continue;
                mp[calcDist(points[i], points[j])]++;
            }
            
            for(auto item:mp) res += item.second * (item.second-1) ; // option for j and k
            
        }
        
        return res;
    }
    
    int calcDist(pair<int, int>& p1, pair<int, int>& p2) {
        int dx = p1.first - p2.first, dy = p1.second - p2.second;
        return dx*dx + dy*dy;
    }
};
