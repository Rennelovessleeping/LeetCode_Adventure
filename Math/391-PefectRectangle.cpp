/**************************************************************************
 * File Name : 391-PefectRectangle.cpp
 *
 * Purpose :
 *
 * Creation Date : 22-04-2017
 *
 * Last Modified : Sat Apr 22 13:52:34 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// If one wants to use an unordered_set of pair<int, int>, one has to provide additional hasher
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.empty() || rectangles[0].empty()) return false;
        unordered_set<string> corners;
        
        int x1 = INT_MAX, y1 = INT_MAX; // bottome-left corner
        int x2 = INT_MIN, y2 = INT_MIN; // top-right corner
        int area = 0;
        
        for(auto const rect:rectangles) {
            x1 = min(x1, rect[0]);
            y1 = min(y1, rect[1]);
            x2 = max(x2, rect[2]);
            y2 = max(y2, rect[3]);
            
            area += (rect[2]-rect[0]) * (rect[3]-rect[1]);
            
            string bottom_left = to_string(rect[0]) + to_string(rect[1]); // bottom left
            if (!corners.insert(bottom_left).second) corners.erase(bottom_left); 
            
            string bottom_right = to_string(rect[2]) + to_string(rect[1]); // bottom right
            if (!corners.insert(bottom_right).second) corners.erase(bottom_right);
            
            string up_left = to_string(rect[0]) + to_string(rect[3]); // up left
            if (!corners.insert(up_left).second) corners.erase(up_left); 
            
            string up_right = to_string(rect[2]) + to_string(rect[3]); // top right
            if (!corners.insert(up_right).second) corners.erase(up_right);
        }
        
        if(corners.size() != 4 || corners.find(to_string(x1) + to_string(y1)) == corners.end() 
            || corners.find(to_string(x1) + to_string(y2)) == corners.end()
            || corners.find(to_string(x2) + to_string(y1)) == corners.end()
            || corners.find(to_string(x2) + to_string(y2)) == corners.end() ) return false;
        
        return area == (y2-y1)*(x2-x1); 
    }
};
