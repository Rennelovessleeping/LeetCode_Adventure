/**************************************************************************
 * File Name : 447-NumberO[CfBoomerangs.cpp
 *
 * Purpose :
 *
 * Creation Date : 07-02-2017
 *
 * Last Modified : Tue Feb  7 20:34:41 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        unordered_map<int, int> ht;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                ht[getDist(points[i], points[j])]++;
            }
            for(auto count:ht) res += count.second*(count.second-1); // combination of 2 out n time factorial(2)
            ht.clear();
        }

        return res;
    }
    
private:
    int getDist(pair<int, int>& pt1, pair<int, int>& pt2){
        return (pt1.first - pt2.first)*(pt1.first - pt2.first) + (pt1.second - pt2.second)*(pt1.second - pt2.second);
    }
    
};
