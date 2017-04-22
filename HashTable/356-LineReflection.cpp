/**************************************************************************
 * File Name : 356-LineReflection.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-04-2017
 *
 * Last Modified : Sat Apr 22 15:45:50 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// sort the points into a symmetric pattern
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.size() <= 1) return true;

        int min_x = INT_MAX, max_x = INT_MIN;
        for(auto& p:points) {
            min_x = min(min_x, p.first);
            max_x = max(max_x, p.first);
        }
        
        int mid = (min_x + max_x)/2;
        auto cmp = [&mid](const pair<int, int>& l, const pair<int, int>& r) {
            if(l.first != r.first) return l.first < r.first;
            if (l.first <= mid) return l.second < r.second;
            else return r.second < l.second;
        };
        sort(points.begin(), points.end(), cmp);
        
        for(int left=0, right=points.size()-1; left <= right; left++, right--) {
            if(points[left].first + points[right].first != min_x + max_x) return false;
            if(points[left].first == points[right].first) return true;
            if(points[left].second != points[right].second) return false;
            while(left+1 <= right && points[left] == points[left+1]) left++;
            while(right-1 >= left && points[right] == points[right-1]) right--;
        }
        
        return true;
    }
};

// Hashmap solution
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n <= 1) return true;
        
        unordered_map<int, set<int>> mp; // {y:x}
        int max_x = INT_MIN, min_x = INT_MAX;
        for(auto& p:points){
            max_x = max(p.first, max_x);
            min_x = min(p.first, min_x);
            mp[p.second].insert(p.first);
        }
        
        for(auto item:mp) {
            set<int>& s = item.second;
            for(auto start=s.begin(), end = s.end(); start!=end; start++) {
                if(*start + *(--end) != min_x + max_x) return false;
                if(start == end) break;
            }
        }
        
        return true;
    }
};
