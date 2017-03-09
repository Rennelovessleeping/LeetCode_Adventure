/**************************************************************************
 * File Name : 42-TrappingRainWater.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-03-2017
 *
 * Last Modified : Wed Mar  8 20:36:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
// Two-pointer solution
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                maxLeft = max(height[left], maxLeft);
                res += maxLeft - height[left];
                left++;
            }
            else{
                maxRight = max(height[right], maxRight);
                res += maxRight - height[right];
                right--;
            }
        }
        
        return res;
    }
};

// Actually one only needs to maintain one maxHeight
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int maxHeight = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                maxHeight = max(height[left], maxHeight);
                res += maxHeight - height[left];
                left++;
            }
            else{
                maxHeight = max(height[right], maxHeight);
                res += maxHeight - height[right];
                right--;
            }
        }
        
        return res;
    }
};

// Maintain a stack of decreasing height, e.g. the left part of a container;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int i = 0;
        int res = 0;
        
        while(i<height.size()){
            if(stk.empty() || height[i] <= height[stk.top()]) stk.push(i++);
            else{
                int tmpIdx = stk.top();
                stk.pop();
                res += stk.empty() ? 0 : (min(height[i],height[stk.top()]) - height[tmpIdx])*(i-stk.top()-1);
            }
        }
        
        return res;
    }
};
