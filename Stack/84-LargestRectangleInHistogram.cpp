/**************************************************************************
 * File Name : 84-LargestRectangleInHistogram.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-03-2017
 *
 * Last Modified : Wed Mar  8 22:27:56 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Keep track of left and right boundary of choosing i'th bar as the min bar in the rectangle;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> stk;
        int i=0;
        while(!stk.empty() || i<heights.size()){
            if(i<heights.size() && (stk.empty() || heights[i] >= heights[stk.top()]) ) stk.push(i++);
            else{
                int tmpIdx = stk.top(); stk.pop();
                res = max(res, heights[tmpIdx]*(stk.empty() ? i : (i-1-stk.top())));
            }
        }
        // one can treat heights[heights.size()] = 0;
        
        return res;
    }
};
