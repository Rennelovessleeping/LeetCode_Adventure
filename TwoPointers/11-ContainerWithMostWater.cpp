/**************************************************************************
 * File Name : 11-ContainerWithMostWater.cpp
 *
 * Purpose :
 *
 * Creation Date : 08-03-2017
 *
 * Last Modified : Wed Mar  8 18:40:55 2017
 *
 * Created By :  Renne Bai
**************************************************************************/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size()-1;
        
        while(i<j){
            int h = min(height[i], height[j]);
            res = max(res, h*(j-i));
            while (i < j &&height[i] <= h) i++;
            while (i < j &&height[j] <= h) j--;
        }
        return res;
    }
};
